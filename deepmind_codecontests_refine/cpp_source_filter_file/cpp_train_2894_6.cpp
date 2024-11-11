#include<bits/stdc++.h>
using namespace std;

vector<int> vis[200010];
vector<int> ans;

void dfs(int v, int p=-1){
  for(int u : vis[v]){
    
    if(u==p) continue;

    ans[u] += ans[v];
    dfs(u,v);
  }
}


int main(){
  int n,q,i;
  cin >> n >> q;

  for(i=0;i<n-1;++i){
    int a,b;
    cin >> a >> b;
    --a;
    --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  ans.resize(n);
  for(i=0;i<q;i++){
    int p,x;
    cin >> p >> x;
    --p;
    ans[p] += x;
  }

  dfs(0);

  for(i=0;i<n;i++){
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
