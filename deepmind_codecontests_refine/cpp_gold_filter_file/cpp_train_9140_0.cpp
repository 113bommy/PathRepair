#include<iostream>
#include<stdio.h>
using namespace std;
double DP[3010][3010];
double X[3010];
int main()
{
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>X[i];
  DP[0][0]=1;
  for(int i=0;i<N;i++)
    for(int j=0;j<=i;j++)
      DP[i+1][j+1]+=DP[i][j]*X[i],
      DP[i+1][j]+=DP[i][j]*(1-X[i]);
  double ans=0;
  for(int i=(N+1)/2;i<=N;i++)
    ans+=DP[N][i];
  printf("%.9lf\n",ans);
  return 0;
}