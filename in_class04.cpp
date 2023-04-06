#include <iostream>
#include<ctime>
#include<chrono>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition (int A[], int p, int r)
    {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r- 1; j++)
    {
    if (A[j] <= x)
    {
        i++;
        swap (&A[i], &A[j]);
        }
        }
        swap (&A[i + 1], &A[r]);
        return (i + 1);
    }
void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
    int q = partition(A, p,r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
    }
}
int main()
{
    int sz=48000;
    int randArray[sz];
    for(int i=0;i<sz;i++){
        randArray[i]=rand()%sz;
    }

    auto start_time = chrono::high_resolution_clock::now();
    quickSort(randArray,0,sz-1);
    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time-start_time);

    cout<<"Elapsed time: "<<elapsed_time.count()<<" ms"<<endl;

    cout << "\nSorted array is \n";
    for (int i = 0; i < sz; i++)
        cout << randArray[i] << " ";
    return 0;
}

    /*clock_t start = clock();
    quickSort(randArray,0,sz-1);
    clock_t end = clock();
    double duration = double(end-start)/CLOCKS_PER_SEC;
    cout<<duration<<" ms"<<endl;

    cout << "\nSorted array is \n";
    for (int i = 0; i < sz; i++)
        cout << randArray[i] << " ";
    return 0;
}*/
