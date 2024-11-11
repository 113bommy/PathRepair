#include <bits/stdc++.h>
using namespace std;
const int MX = 200005;
vector<pair<int, int>> neigh[MX];
int dsu_par[MX];
int dsu_get(int v) {
  if (v == dsu_par[v]) return v;
  return dsu_par[v] = dsu_get(dsu_par[v]);
}
bool dsu_merge(int u, int v) {
  u = dsu_get(u);
  v = dsu_get(v);
  if (u == v) return false;
  dsu_par[u] = v;
  return true;
}
int tin[MX], tout[MX];
bool isAncestor(int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; }
int par[MX][20];
int mx[MX][20];
int LCP(int u, int v) {
  if (isAncestor(u, v)) return u;
  for (int i = 19; i >= 0; i--) {
    if (!isAncestor(par[u][i], v)) {
      u = par[u][i];
    }
  }
  return par[u][0];
}
int getMax(int u, int p) {
  int r = 0;
  for (int i = 19; i >= 0; i--) {
    if (isAncestor(p, par[u][i])) {
      r = max(r, mx[u][i]);
      u = par[u][i];
    }
  }
  return r;
}
int t;
void dfs(int v, int p, int x) {
  tin[v] = t++;
  par[v][0] = p;
  mx[v][0] = x;
  for (int i = 0; i + 1 < 20; i++) {
    par[v][i + 1] = par[par[v][i]][i];
    mx[v][i + 1] = max(mx[v][i], mx[par[v][i]][i]);
  }
  for (auto e : neigh[v]) {
    if (e.first == p) continue;
    dfs(e.first, v, e.second);
  }
  tout[v] = t++;
}
struct Edge {
  int u, v, w;
} e[MX];
int main() {
  int n, m;
  ignore = scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    ignore = scanf("%d %d %d", &u, &v, &w);
    e[i] = {u, v, w};
  }
  sort(e, e + m, [](Edge a, Edge b) { return a.w < b.w; });
  long long sum = 0;
  for (int v = 1; v <= n; v++) dsu_par[v] = v;
  for (int i = 0; i < m; i++) {
    if (dsu_merge(e[i].u, e[i].v)) {
      neigh[e[i].u].emplace_back(e[i].v, e[i].w);
      neigh[e[i].v].emplace_back(e[i].u, e[i].w);
      sum += e[i].w;
    }
  }
  int cnt = 0;
  for (int v = 1; v <= n; v++) {
    if (!par[v][0]) {
      cnt++;
      dfs(v, v, 0);
    }
  }
  int q;
  ignore = scanf("%d", &q);
  while (q--) {
    int a, b;
    ignore = scanf("%d %d", &a, &b);
    if (cnt >= 3) {
      printf("-1\n");
    }
    if (cnt == 2) {
      if (dsu_get(a) == dsu_get(b)) {
        printf("-1\n");
      } else {
        printf("%lld\n", sum);
      }
    } else {
      int lcp = LCP(a, b);
      int r = max(getMax(a, lcp), getMax(b, lcp));
      printf("%lld\n", sum - r);
    }
  }
}
