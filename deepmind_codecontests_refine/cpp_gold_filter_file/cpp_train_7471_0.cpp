#include <bits/stdc++.h>
using namespace std;

const long long  mod=1e9+7;
int main()
{
  int n;
  cin>>n;
  vector<long long>dp(n+1);
  dp[1]=dp[2]=0;
  dp[0]=1;
  for(int i=3;i<=n;i++)
  {
      for(int j=i-3;j>=0;j--)
      {
          (dp[i]+=dp[j])%=mod;
      }
  }  
  cout<<dp[n];
}