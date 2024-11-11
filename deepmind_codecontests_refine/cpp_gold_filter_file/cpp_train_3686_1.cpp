#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, block = 80;
const int logN = 17;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
int n, m, f[N][logN], depth[N], ans[N];
vector<int> g[N], red;
void dfs(int u, int p = 0) {
  f[u][0] = p;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < logN; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = logN - 1; i >= 0; i--) {
    if (depth[f[u][i]] >= depth[v]) u = f[u][i];
  }
  if (u == v) return u;
  for (int i = logN - 1; i >= 0; i--) {
    if (f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }
  }
  return f[u][0];
}
int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
void multi_sourceBFS() {
  queue<pair<int, int> > qu;
  for (int u : red) qu.push(pair<int, int>(0, u)), ans[u] = 0;
  while (!qu.empty()) {
    int u = qu.front().second, du = qu.front().first;
    qu.pop();
    if (ans[u] != du) continue;
    for (int v : g[u]) {
      if (ans[v] > du + 1) {
        ans[v] = du + 1;
        qu.push(pair<int, int>(ans[v], v));
      }
    }
  }
}
void update(int u) {
  red.push_back(u);
  if (red.size() == block) multi_sourceBFS(), red.clear();
}
void query(int u) {
  int res = ans[u];
  for (int v : red) res = min(res, dist(u, v));
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) ans[i] = INF;
  update(1);
  while (m--) {
    int type, u;
    cin >> type >> u;
    if (type == 1)
      update(u);
    else
      query(u);
  }
  return 0;
}
