#include <bits/stdc++.h>
struct interval {
  int l, r;
  int operator<(const interval &i) const { return r < i.r; }
} is[10005];
int n, k, a[10005], tot, app[105][105], cnt[10005], ci, lim, sel[105];
int sell[105], selr[105];
int main() {
  scanf("%d%d", &n, &k);
  tot = n * k;
  lim = (n + k - 2) / (k - 1);
  for (int i = 1; i <= tot; ++i) {
    scanf("%d", a + i);
    app[a[i]][++cnt[a[i]]] = i;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < k; ++j) is[++ci] = (interval){app[i][j], app[i][j + 1]};
  std::sort(is + 1, is + ci + 1);
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= ci; ++i)
    if (!sel[a[is[i].l]]) {
      int can = 1;
      for (int j = is[i].l; j <= is[i].r; ++j) can &= cnt[j] < lim;
      if (can) {
        for (int j = is[i].l; j <= is[i].r; ++j) ++cnt[j];
        sell[a[is[i].l]] = is[i].l;
        selr[a[is[i].r]] = is[i].r;
        sel[a[is[i].l]] = 1;
      }
    }
  for (int i = 1; i <= n; ++i) printf("%d %d\n", sell[i], selr[i]);
  return 0;
}
