#include<bits/stdc++.h>
using namespace std;
int dp[1<<21];
int a[22][22];
int N;

void solve()
{
    dp[0] = 1;
   for(int mask = 1;mask<(1<<N);mask++){
       for(int j=0;j<N;j++)
       {
           if((mask&(1<<j) && a[__builtin_popcount(mask)-1][j]))
           {
               dp[mask] = (dp[mask] + dp[mask ^ (1<<j)])%1000000007;
           }
       }
   }
   cout<<dp[(1<<N)-1]<<"\n";
}


int main()
{
    cin>> N;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    cin>>a[i][j];
    solve();
}