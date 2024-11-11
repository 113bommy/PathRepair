#include<bits/stdc++.h>
using namespace std;
map<pair<int,int> ,int>mp;
int color[100005],mx=0;
vector<int>adj[100005];
void dfs(int u,int par)
{
    int cl=1;
    for(int v:adj[u])
    {
        if(v!=par)
        {
            if(cl==color[mp[{par,u}]])
                cl++;
            mx=max(cl,mx);
            color[mp[{u,v}]]=cl;
            dfs(v,u);
            cl++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}]=i;
        mp[{v,u}]=i;
    }
    dfs(1,0);
    cout<<mx<<endl;
    for(int i=1;i<=n-1;i++)
        cout<<color[i]<<endl;
    return 0;
}
