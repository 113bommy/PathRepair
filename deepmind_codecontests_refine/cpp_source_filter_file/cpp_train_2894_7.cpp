#include <bits/stdc++.h>

using namespace std;
vector<int> to[200005];
vector<int> ans;
void dfs(int v;int p=-1){
  for(int u:to[v]){
    if(u==p){
      continue;
    }
    else{
      ans[u]+=ans[v];
    }
    dfs(u,v);
  }
}
  
int main(){
  int n,q;
  cin >> n >> q;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  ans.resize(n);
  for(int i=0;i<q;i++){
    int p,x;
    cin >> p >> x;
    --p;
    ans[p]+=x;
  }
  dfs(0);
  for(int i=0;i<n;i++){
    cout << ans[i] << endl;
  }
}