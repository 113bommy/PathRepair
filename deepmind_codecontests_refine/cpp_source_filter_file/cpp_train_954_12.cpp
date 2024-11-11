#include <bits/stdc++.h>
using namespace std;
const int MX = 200005;
vector<int> neigh[MX];
int depth[MX];
int par[MX];
void dfs1(int v, int p, int d) {
  par[v] = p;
  depth[v] = d;
  for (int u : neigh[v]) {
    if (u == p) continue;
    dfs1(u, v, d + 1);
  }
}
vector<int> diag;
bool is_diag[MX];
int dfs2(int v, int p) {
  int h = 0;
  for (int u : neigh[v]) {
    if (u == p) continue;
    if (is_diag[u]) continue;
    h = max(h, dfs2(u, v));
  }
  return h + 1;
}
int k;
void dfs3(int v, int p, int x, int d) {
  depth[v] = x;
  x += d;
  if (x < 0) x += k;
  if (x >= k) x -= k;
  for (int u : neigh[v]) {
    if (u == p) continue;
    if (is_diag[u]) continue;
    dfs3(u, v, x, d);
  }
}
int main() {
  int n;
  ignore = scanf("%d %d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    ignore = scanf("%d %d", &u, &v);
    neigh[u].push_back(v);
    neigh[v].push_back(u);
  }
  if (k == 2) {
    dfs1(1, 0, 1);
    printf("Yes\n");
    for (int v = 1; v <= n; v++) {
      printf("%d ", depth[v] % 2 + 1);
    }
    return 0;
  }
  {
    dfs1(1, 0, 1);
    int v = 1;
    for (int i = 1; i <= n; i++) {
      if (depth[i] > depth[v]) v = i;
    }
    dfs1(v, 0, 1);
    v = 1;
    for (int i = 1; i <= n; i++) {
      if (depth[i] > depth[v]) v = i;
    }
    while (v) {
      is_diag[v] = true;
      diag.push_back(v);
      v = par[v];
    }
  }
  for (int i = 0; i < (int)diag.size(); i++) {
    int v = diag[i];
    int d = dfs2(v, 0);
    if (d > 0 && d + i >= k && d + (int)diag.size() - i - 1 >= k) {
      printf("No\n");
      return 0;
    }
    if (d + i >= k) {
      dfs3(v, 0, i % k, 1);
    } else {
      dfs3(v, 0, i % k, -1);
    }
  }
  printf("Yes\n");
  for (int i = 1; i <= n; i++) {
    printf("%d ", depth[i] + 1);
  }
}
