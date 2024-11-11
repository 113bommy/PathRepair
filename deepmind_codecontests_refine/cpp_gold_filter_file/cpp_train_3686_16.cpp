#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
set<int> st[N];
long long int Child[N], Par[N], Res[N], Nod;
long long int tbl[N][21], Dep[N], n, m;
void dfs0(int u, int p) {
  for (auto v : st[u]) {
    if (v == p) continue;
    tbl[v][0] = u;
    Dep[v] = Dep[u] + 1;
    dfs0(v, u);
  }
}
void sparse() {
  dfs0(0, 0);
  tbl[0][0] = 0;
  for (int i = 1; i < 21; i++) {
    for (int j = 0; j < n; j++) {
      tbl[j][i] = tbl[tbl[j][i - 1]][i - 1];
    }
  }
}
int _lca(int u, int v) {
  if (Dep[u] > Dep[v]) swap(u, v);
  int d = Dep[v] - Dep[u];
  for (int i = 0; i < 21; i++) {
    if (d & (1 << i)) v = tbl[v][i];
  }
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (tbl[v][i] != tbl[u][i]) u = tbl[u][i], v = tbl[v][i];
  }
  return tbl[u][0];
}
void dfs1(int u, int p) {
  Child[u] = 1;
  ++Nod;
  for (auto v : st[u]) {
    if (v == p) continue;
    dfs1(v, u);
    Child[u] += Child[v];
  }
}
int dfs2(int u, int p) {
  for (auto v : st[u]) {
    if (v == p || Child[v] <= Nod / 2) continue;
    return dfs2(v, u);
  }
  return u;
}
void Decomposed(int root, int p) {
  Nod = 0;
  dfs1(root, root);
  int centroid = dfs2(root, root);
  if (p == -1) p = centroid;
  Par[centroid] = p;
  for (auto it = st[centroid].begin(); it != st[centroid].end(); ++it) {
    int v = *it;
    st[v].erase(centroid);
    Decomposed(v, centroid);
  }
  st[centroid].clear();
}
long long int dist(int u, int v) {
  return (Dep[u] + Dep[v] - 2 * Dep[_lca(u, v)]);
}
void updt(int u) {
  int x = u;
  while (true) {
    Res[x] = min(Res[x], dist(x, u));
    if (x == Par[x]) break;
    x = Par[x];
  }
}
long long int Qry(int u) {
  int x = u;
  long long int Ret = 1e9 + 7;
  while (true) {
    Ret = min(Ret, dist(u, x) + Res[x]);
    if (x == Par[x]) break;
    x = Par[x];
  }
  return Ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    st[u].insert(v);
    st[v].insert(u);
  }
  sparse();
  Decomposed(0, -1);
  for (int i = 0; i < n; i++) Res[i] = 1e9 + 7;
  updt(0);
  while (m--) {
    int t, v;
    cin >> t >> v;
    --v;
    if (t == 1)
      updt(v);
    else {
      int Ret = Qry(v);
      cout << Ret << "\n";
    }
  }
  return 0;
}
