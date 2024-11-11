#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  while(cin >> n >> m, n){
    vector< vector<int> > g(n);
    for(int i=0;i<m;i++){
      int a,b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    set<int> invite;
    for(int v : g[0]){
      invite.insert(v);
      for(int u : g[v]){
        invite.insert(u);
      }
    }
    cout << invite.size() - 1 << endl;
  }
}