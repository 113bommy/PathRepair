#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 100005, LG = 18, B_SZ = 316;
int n, m;
vector<int> g[N];
int cl[N], vr[N], dst[N];
void bfs() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    dst[i] = (int)2e9;
    if (cl[i]) {
      dst[i] = 0;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (dst[v] > dst[u] + 1) {
        dst[v] = dst[u] + 1;
        q.push(v);
      }
    }
  }
}
int dep[N], jmp[LG + 1][N];
void dfs(int u, int p = -1) {
  for (auto v : g[u]) {
    if (v != p) {
      dep[v] = dep[u] + 1;
      jmp[0][v] = u;
      dfs(v, u);
    }
  }
}
int lca(int u, int v) {
  if (dep[v] > dep[u]) swap(u, v);
  for (int i = LG; i >= 0; --i) {
    if (dep[u] - (1 << i) >= dep[v]) {
      u = jmp[i][u];
    }
  }
  if (u == v) return u;
  for (int j = LG; j >= 0; --j) {
    if (jmp[j][u] != jmp[j][v]) {
      u = jmp[j][u], v = jmp[j][v];
    }
  }
  return jmp[0][u];
}
int dist(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }
void lca_init() {
  dfs(1);
  for (int j = 1; j < LG; ++j) {
    for (int i = 1; i <= n; ++i) {
      jmp[j][i] = jmp[j - 1][jmp[j - 1][i]];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0, u, v; i < n - 1; ++i) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  cl[1] = 1, bfs();
  lca_init();
  int sc = B_SZ;
  vector<int> vt;
  for (int i = 0, t, v; i < m; ++i) {
    if (sc-- == 0) {
      bfs();
      vt.clear();
      sc = B_SZ;
    }
    cin >> t >> v;
    if (t == 1) {
      cl[v] = 1;
      vt.push_back(v);
    } else {
      int x = dst[v];
      for (auto p : vt) {
        x = min(x, dist(v, p));
      }
      cout << x << '\n';
    }
  }
  return 0;
}
