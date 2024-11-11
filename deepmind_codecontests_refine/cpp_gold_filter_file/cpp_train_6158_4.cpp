#include <bits/stdc++.h>
using namespace std;
int n, nxt[200100], f[18][200100], m, a[200100], go[200100], ls[200100],
    fir[200100], nex[200100], to[200100], ans[200100], q;
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) ls[i] = m + 1;
  f[0][m + 1] = m + 1;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  a[n + 1] = a[1];
  for (int i = 1; i <= n; ++i) nxt[a[i]] = a[i + 1];
  for (int i = 1; i <= m; ++i) scanf("%d", a + i);
  for (int i = m; i; --i) f[0][i] = ls[nxt[a[i]]], ls[a[i]] = i;
  for (int j = 1; j <= 17; ++j)
    for (int i = 1; i <= m + 1; ++i) f[j][i] = f[j - 1][f[j - 1][i]];
  for (int i = 1; i <= m; ++i) {
    int x = i;
    for (int j = 17; j >= 0; --j)
      if (n - 1 & 1 << j) x = f[j][x];
    go[i] = x;
  }
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    to[i] = r;
    nex[i] = fir[l];
    fir[l] = i;
  }
  for (int i = m, mn = m + 1; i; --i) {
    mn = min(mn, go[i]);
    for (int o = fir[i]; o; o = nex[o])
      if (to[o] >= mn) ans[o] = 1;
  }
  for (int i = 1; i <= q; ++i) printf("%d", ans[i]);
}
