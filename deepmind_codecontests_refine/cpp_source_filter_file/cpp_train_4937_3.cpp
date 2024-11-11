#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
int par[22][1000005];
int depth[1000005];
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = 22; i >= 0; i--) {
    int p = par[i][u];
    if (depth[p] < depth[v]) continue;
    u = p;
  }
  if (u == v) return u;
  for (int i = 22; i >= 0; i--) {
    if (par[i][u] == par[i][v]) continue;
    u = par[i][u];
    v = par[i][v];
  }
  return par[0][u];
}
int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
int main() {
  int q;
  par[0][2] = par[0][3] = par[0][4] = 1;
  depth[1] = 1;
  depth[2] = depth[3] = depth[4] = 2;
  int n = 4;
  int dia1 = 2;
  int dia2 = 3;
  int d = 2;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    par[0][n + 1] = par[0][n + 2] = x;
    depth[n + 1] = depth[n + 2] = depth[x] + 1;
    for (int i = 1; i <= 21; i++) {
      par[i][n + 1] = par[i - 1][par[i - 1][n + 1]];
      par[i][n + 2] = par[i - 1][par[i - 1][n + 2]];
    }
    int nd1 = dist(n + 1, dia1);
    if (nd1 > d) {
      d = nd1;
      dia2 = n + 1;
    }
    int nd2 = dist(n + 1, dia2);
    if (nd2 > d) {
      d = nd2;
      dia1 = n + 1;
    }
    n += 2;
    printf("%d\n", d);
  }
  return 0;
}
