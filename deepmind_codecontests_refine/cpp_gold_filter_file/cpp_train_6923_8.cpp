#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long> > e[200010];
int U[200010], V[200010];
int dep[200010], par[19][200010];
int pd[200010];
long long den[200010];
void dfs(int v, int p = -1) {
  for (int i = 0; i < e[v].size(); i++) {
    int w = e[v][i].first;
    if (p != w) {
      dep[w] = dep[v] + 1;
      par[0][w] = v;
      den[w] = e[v][i].second;
      dfs(w, v);
    }
  }
}
int lca(int u, int v) {
  if (dep[u] > dep[v]) return lca(v, u);
  int dif = dep[v] - dep[u];
  for (int i = 0; i < 18; i++) {
    if (dif >> i & 1) {
      v = par[i][v];
    }
  }
  if (u == v) return u;
  for (int i = 17; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}
int find(int x) { return x == pd[x] ? x : (pd[x] = find(pd[x])); }
void go(int u, int w, long long &x) {
  if (dep[u] <= dep[w] || !x) return;
  int t = find(u);
  if (u == t) {
    if (den[u] == 1) {
      pd[u] = find(par[0][u]);
    }
    x /= den[u];
    go(par[0][u], w, x);
  } else {
    go(t, w, x);
  }
}
int main() {
  int n, m, u, v;
  long long x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%I64d", &u, &v, &x);
    --u;
    --v;
    U[i] = u;
    V[i] = v;
    e[u].push_back(make_pair(v, x));
    e[v].push_back(make_pair(u, x));
  }
  dfs(0);
  par[0][0] = 0;
  for (int i = 0; i < 18; i++) {
    for (int j = 0; j < n; j++) {
      par[i + 1][j] = par[i][par[i][j]];
    }
  }
  for (int i = 0; i < n; i++) {
    pd[i] = i;
  }
  den[0] = 1;
  while (m--) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d%d%I64d", &u, &v, &x);
      --u;
      --v;
      int w = lca(u, v);
      go(u, w, x);
      go(v, w, x);
      printf("%I64d\n", x);
    } else {
      scanf("%d%I64d", &u, &x);
      --u;
      if (dep[U[u]] < dep[V[u]]) {
        den[V[u]] = x;
      } else {
        den[U[u]] = x;
      }
    }
  }
  return 0;
}
