#include <bits/stdc++.h>
using namespace std;
long long ans, hh, tt, mid, a[110000], b[110000];
int i, n, m;
bool can(long long x) {
  int i, now, j = 1;
  long long xx, yy;
  for (i = 1; i <= n; i++) {
    if (b[j] < a[i])
      xx = a[i] - b[j];
    else
      xx = 0;
    if (xx > x) return 0;
    yy = (x - xx) / 2 > x - xx * 2 ? (x - xx) / 2 : x - xx * 2;
    while (b[j] <= a[i] + yy && j <= m) j++;
    if (j > m) return 1;
  }
  if (j <= m)
    return 0;
  else
    return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (i = 1; i <= m; i++) scanf("%I64d", &b[i]);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  hh = 0;
  tt = 15000000000;
  while (hh <= tt) {
    mid = (hh + tt) >> 1;
    if (can(mid)) {
      ans = mid;
      tt = mid - 1;
    } else
      hh = mid + 1;
  }
  printf("%I64d\n", ans);
}
