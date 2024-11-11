#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int N = 1e5 + 5;
vector<int> g[N];
int sz[N], parent[N], done[N];
int lvl[N];
void dfs(int u, int p) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (done[v] || v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
int find_centroid(int u, int p, int total) {
  for (int v : g[u]) {
    if (done[v] || v == p) continue;
    if (sz[v] + sz[v] > total) return find_centroid(v, u, total);
  }
  return u;
}
int centroid(int u, int p) {
  dfs(u, 0);
  int cnt = sz[u];
  int center = find_centroid(u, 0, cnt);
  done[center] = 1;
  lvl[center] = lvl[p] + 1;
  for (int v : g[center]) {
    if (done[v]) continue;
    parent[centroid(v, center)] = center;
  }
  return center;
}
int main() {
  io();
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  centroid(1, 0);
  for (int i = 1; i <= n; i++) {
    char c = lvl[i] + 'A' - 1;
    cout << c << " ";
  }
}
