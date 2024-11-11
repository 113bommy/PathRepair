#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, u, k, v, d[110], f[110], time=0;
bool vis[110];
vector<int> adj[110];

void dfs (int p)
{
    time++;
    vis[p]=true;
    d[p]=time;
    for (auto u : adj[p])
    {
        if (!vis[u]) dfs(u);
    }
    time++;
    f[p]=time;
}

int main()
{
    memset(vis, false, sizeof(vis));
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>u>>k;
        for (int j=0; j<k; j++)
        {
            cin>>v;
            adj[u].push_back(v);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (!vis[i]) dfs(i);
    }
    for (int i=1; i<=n; i++)
    {
        cout<<i<<' '<<d[i]<<' '<<f[i]<<'\n';
    }
    return 0;
}

