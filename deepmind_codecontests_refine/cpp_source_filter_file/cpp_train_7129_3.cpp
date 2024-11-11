#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> vertices, g[N];
bool val = 1;
int mark[N], d[N];
bool dfs(int v, int col) {
  mark[v] = col;
  bool isval = 1;
  vertices.push_back(v);
  for (auto u : g[v]) {
    if (!mark[u])
      isval &= dfs(u, 3 - col);
    else if (mark[u] == col)
      return false;
  }
  return isval;
}
int bfs(int v) {
  queue<int> q;
  q.push(v);
  d[v] = 0;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (auto u : g[v]) {
      if (d[u] > d[v] + 1) {
        d[u] = d[v] + 1;
        q.push(u);
      }
    }
  }
  int mx = 0;
  for (auto u : vertices) mx = max(mx, d[u]);
  return mx;
}
int diameter(int v) {
  vertices.clear();
  val &= dfs(v, 1);
  int mx = 0;
  for (auto v : vertices) {
    for (auto u : vertices) d[u] = 1e9;
    mx = max(mx, bfs(v));
  }
  return mx;
}
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) ans += diameter(i);
  if (val == 0) return cout << -1, 0;
  cout << ans << "\n";
}
