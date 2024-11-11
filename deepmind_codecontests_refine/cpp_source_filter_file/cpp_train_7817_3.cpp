#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10, L = 18;
int n, m, nq;
vector<int> g[M];
int up[M][L] = {0};
int d[M] = {0}, tin[M], tout[M];
set<pair<int, int>> es;
int go_up(int v, int k) {
  for (int i = L - 1; i >= 0; i--) {
    if (k >= (1 << i)) {
      k -= 1 << i;
      v = up[v][i];
    }
  }
  return v;
}
bool upper(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
int get_lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = L; i >= 0; --i)
    if (!upper(up[a][i], b)) a = up[a][i];
  return up[a][0];
}
int t = 0;
void dfs(int v) {
  tin[v] = t++;
  for (auto &to : g[v]) {
    if (d[v] + 1 != d[to]) continue;
    dfs(to);
  }
  tout[v] = t++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> nq;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
    es.insert({u, v});
  }
  memset(d, -1, sizeof(d));
  d[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto &to : g[v]) {
      if (d[to] == -1) {
        d[to] = d[v] + 1;
        q.push(to);
        up[to][0] = v;
        for (int i = 1; i < L; i++) up[to][i] = up[up[to][i - 1]][i - 1];
      }
    }
  }
  dfs(0);
  while (nq--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int lca = get_lca(u, v);
    int res = d[u] - d[lca] + d[v] - d[lca];
    if (lca != u && lca != v) {
      int tu = go_up(u, d[u] - d[lca] - 1);
      int tv = go_up(v, d[v] - d[lca] - 1);
      if (tu > tv) swap(tu, tv);
      if (es.count({tu, tv})) res--;
    }
    cout << res << "\n";
  }
  return 0;
}
