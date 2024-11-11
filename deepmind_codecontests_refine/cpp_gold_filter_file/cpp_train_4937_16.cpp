#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, q;
int l[N];
int p[N];
int fa[N][20];
void add(int u, int f) {
  l[u] = l[f] + 1;
  fa[u][0] = f;
  for (int i = 1; i < 20; ++i) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  }
}
int lca(int x, int y) {
  if (l[x] < l[y]) swap(x, y);
  int d = l[x] - l[y];
  for (int i = 0; i < 20; ++i) {
    if (d >> i & 1) x = fa[x][i];
  }
  if (x == y) return x;
  for (int i = 19; i >= 0; --i) {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return fa[x][0];
}
int dist(int u, int v) {
  int p = lca(u, v);
  return l[u] + l[v] - l[p] * 2;
}
int main() {
  scanf("%d", &q);
  n = 4;
  fa[2][0] = fa[3][0] = fa[4][0] = 1;
  l[2] = l[3] = l[4] = 1;
  int u = 2, v = 3, d = 2;
  while (q--) {
    int p;
    scanf("%d", &p);
    add(++n, p);
    add(++n, p);
    int l1 = dist(n, u), l2 = dist(n, v);
    if (l1 >= l2 && l1 >= d) {
      v = n;
      d = l1;
    } else if (l2 >= l1 && l2 >= d) {
      u = n;
      d = l2;
    }
    printf("%d\n", d);
  }
  return 0;
}
