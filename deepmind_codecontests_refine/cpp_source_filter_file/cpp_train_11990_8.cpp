#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, tot, sd[N * 2], a[N * 2], Ans[N * 2], in[N * 2], l, out[N * 2],
    fa[20][N * 2], f[N], fi[N * 2], ne[N * 2], zz[N * 2];
struct Ask {
  int x, y, z, from;
} A[N * 5];
void jb(int x, int y) {
  ne[++tot] = fi[x];
  fi[x] = tot;
  zz[tot] = y;
}
int pd(int x, int y) {
  if (!x) return 1;
  return in[x] <= in[y] && out[x] >= out[y];
}
void dfs(int x, int y, int z) {
  fa[0][x] = y;
  in[x] = ++l;
  sd[x] = z;
  for (int i = fi[x]; i; i = ne[i])
    if (zz[i] != x) dfs(zz[i], x, z + 1);
  out[x] = ++l;
}
int cmp(Ask x, Ask y) { return x.z < y.z; }
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
int lca(int x, int y) {
  if (x == y) return x;
  if (sd[x] < sd[y]) swap(x, y);
  for (int i = 19; i >= 0; i--)
    if (!pd(fa[i][x], y)) x = fa[i][x];
  return fa[0][x];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].z);
    A[i].from = i;
  }
  sort(A + 1, A + m + 1, cmp);
  int cnt = n;
  for (int i = 1; i < 2 * n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    int x = find(A[i].x), y = find(A[i].y);
    if (x != y) {
      f[x] = f[y] = f[++cnt];
      a[cnt] = A[i].z;
      jb(cnt, x);
      jb(cnt, y);
      A[i].from = 0;
    }
  }
  dfs(cnt, 0, 0);
  for (int i = 1; i <= 19; i++)
    for (int j = 1; j < n * 2; j++) fa[i][j] = fa[i - 1][fa[i - 1][j]];
  for (int i = 1; i <= m; i++)
    if (A[i].from) Ans[A[i].from] = a[lca(A[i].x, A[i].y)];
  for (int i = 1; i <= m; i++)
    if (Ans[i]) printf("%d\n", Ans[i]);
  return 0;
}
