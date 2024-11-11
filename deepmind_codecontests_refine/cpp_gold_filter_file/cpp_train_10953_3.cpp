#include <bits/stdc++.h>
using namespace std;
int n, m, num[5009], par[5009], dep[5009], a[5009], b[5009], g[5009], x[5009],
    y[5009];
vector<int> t[5009];
void dfs(int u, int p, int d) {
  dep[u] = d;
  par[u] = p;
  for (int i = 0; i < t[u].size(); i++)
    if (t[u][i] != p) dfs(t[u][i], u, d + 1);
}
void lca(int u, int v, int w) {
  while (dep[u] > dep[v]) {
    num[u] = max(num[u], w);
    u = par[u];
  }
  while (dep[v] > dep[u]) {
    num[v] = max(num[v], w);
    v = par[v];
  }
  while (u != v) {
    num[u] = max(num[u], w);
    num[v] = max(num[v], w);
    u = par[u];
    v = par[v];
  }
}
bool check(int u, int v, int w) {
  while (dep[u] > dep[v]) {
    if (num[u] == w) return 1;
    u = par[u];
  }
  while (dep[v] > dep[u]) {
    if (num[v] == w) return 1;
    v = par[v];
  }
  while (u != v) {
    if (num[u] == w) return 1;
    if (num[v] == w) return 1;
    u = par[u];
    v = par[v];
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", x + i, y + i);
    t[x[i]].push_back(y[i]);
    t[y[i]].push_back(x[i]);
  }
  dfs(1, 0, 0);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", a + i, b + i, g + i);
    lca(a[i], b[i], g[i]);
  }
  for (int i = 0; i < m; i++)
    if (!check(a[i], b[i], g[i])) {
      printf("-1\n");
      return 0;
    }
  for (int i = 0; i < n - 1; i++)
    printf("%d ", max(num[dep[x[i]] > dep[y[i]] ? x[i] : y[i]], 1));
  return 0;
}
