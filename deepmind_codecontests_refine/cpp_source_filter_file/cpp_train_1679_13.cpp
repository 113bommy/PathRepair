#include <bits/stdc++.h>
using namespace std;
long long ans, n, tot, e[1000001], nt[1000001], hd[1000001], f[500001][21],
    a[500001], rt;
void build(long long x, long long y) {
  tot++;
  e[tot] = y;
  nt[tot] = hd[x];
  hd[x] = tot;
}
void dfs(long long x, long long fa) {
  long long i, mn = a[fa], j;
  f[x][0] = fa;
  for (j = 1; j <= 20; j++) {
    f[i][j] = f[f[i][j - 1]][j - 1];
    if (!f[i][j]) break;
    mn = min(mn, a[f[i][j]] * (j + 1));
  }
  mn = min(mn, (j + 1) * a[rt]);
  if (fa) ans += mn + a[x];
  for (i = hd[x]; i; i = nt[i]) {
    if (e[i] == fa) continue;
    dfs(e[i], x);
  }
}
int main() {
  long long i, x, y;
  a[0] = 1e9;
  rt = 0;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] < a[rt]) rt = i;
  }
  for (i = 1; i < n; i++) {
    scanf("%lld%lld", &x, &y);
    build(x, y);
    build(y, x);
  }
  dfs(rt, 0);
  printf("%lld", ans);
}
