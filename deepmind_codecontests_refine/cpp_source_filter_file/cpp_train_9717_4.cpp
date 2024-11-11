#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
int const M = 21;
vector<int> G[N], GB[N];
vector<int> vec;
int dfn[N], low[N], in[N], comp[N];
int ndfn = 0, order = 0;
void dfs(int u, int p = -1) {
  dfn[u] = low[u] = ++ndfn;
  in[u] = 1;
  vec.push_back(u);
  for (int v : G[u]) {
    if (v == p) continue;
    if (!dfn[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else if (in[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    int x = -1;
    while (x != u) {
      x = vec.back();
      in[x] = 0;
      vec.pop_back();
      comp[x] = u;
    }
  }
}
int par[N][M], depth[N], Tin[N], Tout[N];
int dfs2(int u, int p = 0, int d = 0) {
  Tin[u] = ++order;
  depth[u] = d;
  par[u][0] = p;
  for (int i = 1; i < M; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (int v : GB[u]) {
    if (v != p) dfs2(v, u, d + 1);
  }
  Tout[u] = ++order;
}
int anc(int u, int v) { return Tin[u] <= Tin[v] && Tout[u] >= Tout[v]; }
int go_up(int u, int v) {
  for (int i = M - 1; i <= 0; i--) {
    if (!anc(par[u][i], v)) u = par[u][i];
  }
  return u;
}
int lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  return par[go_up(u, v)][0];
}
int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    for (int j : G[i]) {
      int ci = comp[i];
      int cj = comp[j];
      if (ci != cj && ci < cj) {
        GB[ci].push_back(cj);
        GB[cj].push_back(ci);
      }
    }
  }
  dfs2(0);
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cout << dist(comp[a], comp[b]) << endl;
  }
}
