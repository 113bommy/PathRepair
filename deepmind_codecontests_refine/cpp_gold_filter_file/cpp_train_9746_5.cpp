#include <bits/stdc++.h>
const int N = 100005;
int fa[N], deep[N], to[N << 1], f[N], n, x, y, siz[N], size[N], edge, Q;
long long sum[N], Ans, tot;
int Next[N << 1], last[N];
void add(int x, int y) {
  to[++edge] = y;
  Next[edge] = last[x];
  last[x] = edge;
}
long long A(int x, int y) {
  if (y == 2) return (long long)x * (x - 1);
  if (y == 3) return (long long)x * (x - 1) * (x - 2);
}
void dfs(int x, int y) {
  fa[x] = y, deep[x] = deep[y] + 1;
  siz[x] = 1;
  for (int i = last[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == y) continue;
    dfs(u, x);
    siz[x] += siz[u];
    sum[x] += A(siz[u], 2);
  }
  sum[x] += A(n - siz[x], 2);
}
int find(int x) {
  if (x == f[x]) return f[x];
  return f[x] = find(f[x]);
}
void merge(int x, int fx) {
  Ans -= size[x] * sum[x], Ans -= size[fx] * sum[fx];
  sum[x] -= A(n - siz[x], 2);
  sum[fx] -= A(siz[x], 2);
  sum[fx] += sum[x];
  f[x] = fx;
  size[fx] += size[x];
  Ans += size[fx] * sum[fx];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) f[i] = i, size[i] = 1;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  tot = A(n, 3), Ans = 0;
  for (int i = 1; i <= n; i++) Ans = Ans + sum[i];
  printf("%lld\n", tot - Ans);
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d", &x, &y);
    x = find(x), y = find(y);
    while (x != y) {
      if (deep[x] < deep[y]) std::swap(x, y);
      int fx = find(fa[x]);
      merge(x, fx);
      x = fx;
    }
    printf("%lld\n", tot - Ans);
  }
}
