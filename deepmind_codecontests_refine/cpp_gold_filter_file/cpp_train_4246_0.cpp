#include<bits/stdc++.h>
#define MX 200005
using namespace std;
vector<int>adj[MX];
int vis[MX];
int dfs(int u){
  int ret=1;
  vis[u]=1;
  for(int v:adj[u])
    if(!vis[v])ret+=dfs(v);
  return ret;
}
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mx=1;
  for(int i=1;i<=n;i++)
    if(!vis[i])
      mx=max(mx,dfs(i));
  cout<<mx<<endl;
  return 0;
}