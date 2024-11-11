#include <bits/stdc++.h>
using namespace std;

const int N=1000010;

vector<int> e[N];
int n,sg[N],u,v;

void dfs(int u,int fa)
{
    sg[u]=0;
    for(auto v : e[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        sg[u]^=sg[v]+1;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<n;++i)
    {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    puts(sg[1]?"Alice":"Bob");
}