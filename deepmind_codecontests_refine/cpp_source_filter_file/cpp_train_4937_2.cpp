#include <bits/stdc++.h>
using namespace std;
const int Sn = 500050;
int q, v, d1, d2, dn, dL, dep[Sn], fa[Sn][21];
int lca(int u, int v) {
  int ret = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int j = 20; j >= 0; j--)
    if (dep[u] - dep[v] >> j & 1) u = fa[u][j], ret += 1 << j;
  if (u == v) return ret;
  for (int j = 20; j >= 0; j--)
    if (fa[u][j] != fa[v][j]) {
      u = fa[u][j], ret += 1 << j;
      v = fa[v][j], ret += 1 << j;
    }
  return ret + 2;
}
void newnode(int ff) {
  dep[++dn] = dep[ff] + 1;
  fa[dn][0] = ff;
  for (int j = 1; j <= 20; j++) fa[dn][j] = fa[fa[dn][j - 1]][j - 1];
  int L1 = lca(d1, dn), L2 = lca(d2, dn);
  if (L1 > L2 && L1 > dL) dL = L1, d2 = dn;
  if (L2 > L1 && L2 > dL) dL = L2, d1 = dn;
}
int main() {
  dn = 4;
  d1 = 2, d2 = 4, dL = 2;
  dep[2] = dep[3] = dep[4] = 1;
  fa[2][0] = fa[3][0] = fa[4][0] = 1;
  for (scanf("%d", &q); q--;) {
    scanf("%d", &v);
    newnode(v);
    newnode(v);
    printf("%d\n", dL);
  }
}
