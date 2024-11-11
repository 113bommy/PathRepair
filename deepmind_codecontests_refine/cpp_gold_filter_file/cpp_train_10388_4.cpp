#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <ll> tree[200008];
ll arr[200009];
int ans[200009];
vector <ll> dp(200009,LLONG_MAX);
void dfs(int cur,int p)
{
    int pos=lower_bound(dp.begin(),dp.end(),arr[cur])-dp.begin();
    ll x=dp[pos];
    dp[pos]=arr[cur];

    for(ll i:tree[cur])
    {
        if(i!=p)
            dfs(i,cur);
    }
    ans[cur]=lower_bound(dp.begin(),dp.end(),LLONG_MAX)-dp.begin();
    dp[pos]=x;


}
int main()
{
    ll i,j,k,l,m,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0,-1);
    for(i=0;i<n;i++)
        cout<<ans[i]<<endl;


}
