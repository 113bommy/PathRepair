#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
struct LCA {
  int N, logN; // logN-1 == floor(lg(N-1))
  vector<vector<int>> G;
  vector<int> depth;
  // vから根の方向に2^k回登ったときのノード parent[k][v]
  vector<vector<int>> parent;
 
  LCA(int size) : N(size), G(size), depth(size) {
    logN = 0;
    for(int x = 1; x < N; x *= 2) logN++;
    parent.assign(max(logN, 1), vector<int>(N));
  }
 
  // どちらが根であってもOK
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
 
  void dfs(int v, int par, int dep) {
    depth[v] = dep;
    parent[0][v] = par;
    for(int next : G[v]) {
      if(next != par) dfs(next, v, dep + 1);
    }
  }
 
  void init(int root) {
    dfs(root, -1, 0);
    for(int k = 1; k < logN; k++) {
      for(int v = 0; v < N; v++) {
        if(parent[k - 1][v] == -1) parent[k][v] = -1;
        else parent[k][v] = parent[k - 1][parent[k - 1][v]];
      }
    }
  }
 
  int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v); // vのほうが深くなる
    // uとvの深さが同じになるまでvを根の方向に移動する
    for(int k = 0; k < logN; k++) {
      if(((depth[v] - depth[u]) >> k) & 1) {
        v = parent[k][v];
      }
    }
    if(u == v) return u;
    for(int k = logN - 1; k >= 0; k--) {
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
 
int main() {
  cin.tie(nullptr);
  int N; cin >> N;
  LCA lca(N);
  for(int u = 0; u < N; u++) {
    int k; cin >> k;
    while(k--) {
      int v; cin >> v;
      lca.add_edge(u, v);
    }
  }
  lca.init(0);
  int Q; cin >> Q;
  while(Q--) {
    int u, v; cin >> u >> v;
    cout << lca.lca(u, v) << endl;
  }
}