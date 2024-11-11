#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  	cin>>a[i];
  int dp[n+1];
  dp[1]=0;
  dp[2]=abs(a[1]-a[0]);
  for(int i=3;i<=n;i++)
  	dp[i]=min((abs(a[i-1]-a[i-2])+dp[i-1]),(abs(a[i-1]-a[i-3])+dp[i-2]));
  cout<<dp[n]<<endl;
}