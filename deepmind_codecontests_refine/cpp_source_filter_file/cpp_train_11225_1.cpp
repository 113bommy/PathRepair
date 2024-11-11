#include<iostream>
using namespace std;
long long dp[1002][1002],sum[1001][1002],C[1001][1001];
int main()
{
  int n,k,m;
  cin>>n>>k>>m;
  for (int i=1;i<=k+1;++i)
    {
     dp[1][i]=1;
     sum[1][i]=i;
    }
  for (int i=0;i<=n;++i)
    C[i][0]=1;
  for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j)
      C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
  for (int i=2;i<=n+1;++i)
    for (int j=1;j<=k+1;++j)
      {
        for (int t=1;t<=i-1;++t)
	  dp[i][j]=(dp[i][j]+dp[t][j]*sum[i-t][j-1]%m*C[i-2][t-1])%m;
	sum[i][j]=(sum[i][j-1]+dp[i][j])%m;
      }
  cout<<dp[n+1][k+1]<<endl;
  return 0;
}