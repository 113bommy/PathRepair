#include <bits/stdc++.h>
long long color[50], f[50][50], vis[50];
long long n, m, cnt1, cnt2, deg[50], ans;
long long a[2001000], b[2001000];
bool bo = true;
void dfs(long long x, long long col) {
  vis[x] = 1, color[x] = col;
  for (long long i = 1; i <= n; i++) {
    if (!f[x][i]) continue;
    if (vis[i]) {
      if (color[i] == color[x]) bo = false;
      continue;
    }
    dfs(i, col ^ 1);
  }
}
signed main() {
  scanf("%lld%lld", &n, &m);
  if (m <= 2) return puts("0"), 0;
  for (long long i = 1, x, y; i <= m; i++) {
    scanf("%lld%lld", &x, &y);
    f[x][y] = f[y][x] = 1;
    deg[x]++, deg[y]++;
  }
  for (long long i = 1; i <= n; i++)
    if (deg[i] == 0) cnt1++;
  for (long long i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, 0), cnt2++;
  ans = 1ll << n;
  ans = ans + (1ll << cnt1 + 1) + (1ll << cnt2) * bo - (1ll << cnt2);
  long long sz1 = n / 2, sz2 = n - sz1;
  for (long long i = 0; i < (1 << sz2); i++) {
    bool bo = true;
    for (long long j = 1; j <= sz2; j++) a[j] = i >> (j - 1) & 1;
    for (long long j = 1; j <= sz2; j++)
      for (long long k = j + 1; k <= sz2; k++)
        if (a[k] == a[j] && a[j] == 1 && f[j + sz1][k + sz1]) bo = false;
    if (bo) b[i] = 1;
  }
  for (long long i = 0; i < sz2; i++)
    for (long long j = 0; j < (1 << sz2); j++)
      if (j >> i & 1) b[j] += b[j ^ (1 << i)];
  memset(a, 0, sizeof(a));
  long long res = 0;
  for (long long i = 0; i < (1 << sz1); i++) {
    for (long long j = 1; j <= sz1; j++) a[j] = i >> (j - 1) & 1;
    bool bo = true;
    for (long long j = 1; j <= sz1; j++)
      for (long long k = j + 1; k <= sz1; k++)
        if (a[k] == a[j] && a[j] == 1 && f[j][k]) bo = false;
    if (!bo) continue;
    long long x = 0;
    for (long long j = 1; j <= sz1; j++) {
      if (a[j] == 0) continue;
      for (long long k = sz1 + 1; k <= n; k++)
        if (f[j][k]) x ^= 1 << (k - sz1 - 1);
    }
    res += b[(1 << sz2) - 1 - x];
  }
  ans = ans - res * 2;
  printf("%lld\n", ans);
}
