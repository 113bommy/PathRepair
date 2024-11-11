#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A;
const int SZ = 200100;
const int INF = 1000000000;
vector<vector<int> > adj(SZ);
vector<int> comp(SZ);
vector<vector<int> > adjcomp(SZ);
map<int, set<int> > viscomp;
bool vis[SZ];
void dfs(int u, int c) {
  vis[u] = 1;
  comp[u] = c;
  for (auto v : adj[u]) {
    if (vis[v] == 0 and A[v] == A[u]) {
      dfs(v, c);
    }
    if (vis[v]) {
      if (comp[v] != comp[u] and viscomp[comp[u]].count(comp[v]) == 0) {
        adjcomp[comp[v]].push_back(comp[u]);
        adjcomp[comp[u]].push_back(comp[v]);
        viscomp[comp[v]].insert(comp[u]);
        viscomp[comp[u]].insert(comp[v]);
      }
    }
  }
}
bool vis1[SZ];
int parents[SZ];
int level[SZ];
void dfs_path(int u, int p, int l) {
  vis1[u] = 1;
  parents[u] = p;
  level[u] = l;
  for (auto v : adjcomp[u]) {
    if (vis1[v] == 0) {
      dfs_path(v, u, l + 1);
    }
  }
}
int main() {
  cin >> N;
  A = vector<int>(N);
  for (auto &i : A) cin >> i;
  int u, v;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int c = 0;
  for (int i = 0; i < N; i++) {
    if (vis[i] == 0) {
      dfs(i, c);
      c++;
    }
  }
  dfs_path(0, -1, 0);
  int level_min = 0, node = 0;
  for (int i = 0; i < c; i++) {
    if (level[i] >= level_min) {
      level_min = level[i];
      node = i;
    }
    vis1[i] = 0;
  }
  dfs_path(node, -1, 0);
  level_min = 0;
  int node2 = 0;
  for (int i = 0; i < c; i++) {
    if (level[i] >= level_min) {
      level_min = level[i];
      node2 = i;
    }
  }
  int diametro = 0;
  for (int x = node2; x >= 0; x = parents[x]) {
    diametro++;
  }
  if (diametro == 1) {
    cout << 0;
    return 0;
  }
  if (diametro % 2 == 0) {
    cout << diametro / 2;
  } else {
    cout << (diametro + 1) / 2;
  }
  return 0;
}
