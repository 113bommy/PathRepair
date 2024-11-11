#include <bits/stdc++.h>
using namespace std;
int n, x, y, nodes;
map<int, int> M;
int N[100000];
int vis[100000];
vector<int> adj[2 * 100000];
void init() {
  M.clear();
  nodes = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 2 * n; ++i) adj[i].clear();
}
void dfs(int node) {
  cout << N[node] << " ";
  vis[node] = 1;
  int nv = adj[node].size();
  for (int i = 0; i < nv; ++i) {
    int son = adj[node][i];
    if (!vis[son]) dfs(son);
  }
}
int main() {
  while (cin >> n) {
    init();
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      if (M.find(x) == M.end()) {
        M[x] = nodes;
        N[nodes] = x;
        nodes++;
      }
      if (M.find(y) == M.end()) {
        M[y] = nodes;
        N[nodes] = y;
        nodes++;
      }
      adj[M[x]].push_back(M[y]);
      adj[M[y]].push_back(M[x]);
    }
    for (int i = 0; i < nodes; ++i)
      if (adj[i].size() == 1) {
        dfs(i);
        break;
      }
    cout << endl;
  }
}
