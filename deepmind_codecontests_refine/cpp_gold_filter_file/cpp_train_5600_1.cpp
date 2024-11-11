#include<bits/stdc++.h>
using namespace std;
const int V=50;
const int MX=1e9+7;
int n,a[20],b[20],off[20][20],dp[1<<20][50];
int fun(int mask,int val)
{
    int ans=MX,d=0;
    if(mask==(1<<n)-1) return 0;
    if(dp[mask][val]!=-1) return dp[mask][val];
    int ln=__builtin_popcount(mask);
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i)) continue;
        if(off[ln][i]>=val)
        ans=min(ans,d+fun(mask|(1<<i),off[ln][i]));
        d++;
    }
    return dp[mask][val]=ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        off[i][j]=(i%2==j%2)?a[j]:b[j];
    }
    memset(dp,-1,sizeof(dp));
    int res=fun(0,0);
    if(res>=MX) cout<<"-1";
    else
    cout<<res;
    return 0;
}