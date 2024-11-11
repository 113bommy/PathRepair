#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main()
{
    AC
    int n,w,r=0;
    cin>>n>>w;
    vector<ll> dp(100001,1e10);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        int wei,val;
        cin>>wei>>val;
        for(int j=100000;j>=val;j--)
            dp[j]=min(dp[j],dp[j-val]+wei);
    }
    for(int i=1;i<dp.size();i++)
        if(dp[i]<=w) r=i;
    cout<<r<<'\n';
}