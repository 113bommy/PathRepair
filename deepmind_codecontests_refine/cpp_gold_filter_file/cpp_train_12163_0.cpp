#include<iostream>
#include<vector>

using namespace std;

int main()
{int N ; cin >> N;
 vector<int> A(N+2,0);//A[0],A[N+1]を発着地点とする
 for(int i = 1; i <= N;i++)
 {cin >> A[i];}
 
 int total = 0;
 
 for(int i = 0; i <= N; i++)
 {total += abs(A[i+1] - A[i]);}
 
 for(int j = 1; j <= N; j++)
 {int c = abs(A[j+1] - A[j]) + abs(A[j] - A[j-1]) - abs(A[j+1] - A[j-1]);
  cout << total - c << endl;}
 
 return 0;
}