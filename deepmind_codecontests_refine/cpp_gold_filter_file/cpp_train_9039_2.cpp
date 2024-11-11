#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1000010];
int n,poi[1000010],u,v;

void dfs(int u,int fa)
{
    poi[u]=0;
    for(auto v : edge[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        poi[u]^=poi[v]+1;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i)
    {
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    puts(poi[1]?"Alice":"Bob");
}