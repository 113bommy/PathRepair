#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long infLL = 0x3f3f3f3f3f3f3f3fLL;
const int hash_mod = 1000037;
const double eps = 1e-10;
const double pi = acos(-1);
const int maxn = 1000000 + 5;
int n = 3, a = 1, b = 2;
int q, res = 2;
int dep[maxn];
int f[maxn][20];
void add(int u, int v) {
  dep[v] = dep[u] + 1;
  f[v][0] = u;
  for (int i = 1; i < 20; ++i) f[v][i] = f[f[v][i - 1]][i - 1];
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 0; i < 20; ++i)
    if ((dep[x] - dep[y]) & (1 << i)) x = f[x][i];
  for (int i = 19; i >= 0; --i)
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  return f[x][0];
}
int query(int x, int y) { return dep[x] + dep[y] - dep[lca(x, y)] * 2; }
int main() {
  dep[1] = dep[2] = dep[3] = 1;
  scanf("%d", &q);
  while (q--) {
    int v;
    scanf("%d", &v);
    --v;
    add(v, ++n);
    add(v, ++n);
    if (query(n, a) > res) {
      ++res;
      b = n;
    } else if (query(n, b) > res) {
      ++res;
      a = n;
    }
    printf("%d\n", res);
  }
  return 0;
}
