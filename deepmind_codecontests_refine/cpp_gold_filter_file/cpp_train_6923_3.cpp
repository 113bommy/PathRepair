#include <bits/stdc++.h>
using namespace std;
long long Head[500010 << 1], Next[500010 << 1], Ver[500010 << 1],
    Edge[500010 << 1], From[500010 << 1];
long long n, m;
long long fa[500010], val[500010];
long long tot = 0;
long long f[500010][21], dep[500010];
void Add(long long x, long long y, long long z) {
  Ver[++tot] = y;
  Next[tot] = Head[x];
  Head[x] = tot;
  Edge[tot] = z;
  From[tot] = x;
}
long long find(long long x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void dfs(long long x, long long faa) {
  f[x][0] = faa;
  dep[x] = dep[faa] + 1;
  for (long long i = 1; i <= 17; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  for (long long i = Head[x]; i; i = Next[i]) {
    long long y = Ver[i], w = Edge[i];
    if (y == faa) continue;
    if (w == 1) fa[y] = find(x);
    val[y] = w;
    dfs(y, x);
  }
}
long long LCA(long long x, long long y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (long long i = 17; i >= 0; i--) {
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    if (x == y) return x;
  }
  for (long long i = 17; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) fa[i] = i;
  for (long long i = 1; i <= n - 1; i++) {
    long long x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    Add(x, y, z);
    Add(y, x, z);
  }
  dfs(1, 0);
  for (long long i = 1; i <= m; i++) {
    long long order, x, y, z;
    scanf("%lld", &order);
    if (order == 1) {
      scanf("%lld%lld%lld", &x, &y, &z);
      long long pos = LCA(x, y), a = x, b = y;
      while (dep[a] > dep[pos] && z) {
        if (val[a]) z /= val[a];
        a = find(f[a][0]);
      }
      while (dep[b] > dep[pos] && z) {
        if (val[b]) z /= val[b];
        b = find(f[b][0]);
      }
      printf("%lld\n", z);
    } else if (order == 2) {
      scanf("%lld%lld", &x, &y);
      long long A = From[x << 1], B = Ver[x << 1];
      if (f[A][0] == B)
        z = A;
      else
        z = B;
      val[z] = y;
      if (val[z] == 1) fa[z] = find(f[z][0]);
    }
  }
  return 0;
}
