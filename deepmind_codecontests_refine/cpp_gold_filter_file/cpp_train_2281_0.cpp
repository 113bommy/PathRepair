#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

int N, R, p, c, i, j;

int main()
{
   while ( cin >> N >> R && N >0 )
   {
      int A[N];
      for ( i = 0; i < N; i++)
         {
            A[i] = N - i;
         }
      for ( j = 0; j<R; j++)
         {
            cin >> p >> c;
            rotate(A,A+(p-1),A+(p+c-1));
         }
      cout << A[0] <<endl;
   }
}