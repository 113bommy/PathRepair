#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
#define int long long

vector<int> ans;
vector<int> to[200005];
void dfs(int x,int p=-1){
  for(int i : to[x]){
    if(p == i) continue;
    ans[i] += ans[x];
    dfs(i,x);
  }
}

int main(){
  int n,q;
  cin>>n>>q;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  
  ans.resize(n);
  rep(i,q){
    int p,x;
    cin>>p>>x;
    p--;
    ans[p] += x;
  }
  dfs(0);
  rep(i,n) cout << ans[i] << endl;
}