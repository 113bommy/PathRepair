#include <bits/stdc++.h>
using namespace std;
int n, m, t, d, v, vt, vd, len, x3, x4, y3, y4, a[100010], b[100010], q;
int main() {
  scanf("%d%d%d%d%d", &n, &m, &t, &d, &v);
  for (int i = 1; i <= t; i++) scanf("%d", a + i);
  for (int i = 1; i <= d; i++) scanf("%d", b + i);
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
    int len = abs(x3 - x4), vd = len % v ? len / v + 1 : len / v, vt = len;
    if (y3 > y4) swap(y3, y4);
    int t1 = lower_bound(a + 1, a + t + 1, y3) - a,
        t2 = lower_bound(a + 1, a + t + 1, y4) - a,
        d1 = lower_bound(b + 1, b + d + 1, y3) - b,
        d2 = lower_bound(b + 1, b + d + 1, y4) - b;
    if (d1 && d1 <= d && b[d1] < y4) {
      printf("%d\n", y4 - y3 + vd);
      continue;
    }
    d1--;
    int ans = 1 << 30;
    if (d1 && d1 <= d) ans = min(ans, y4 - y3 + vd + 2 * (y3 - b[d1]));
    if (d2 && d2 <= d) ans = min(ans, y4 - y3 + vd + 2 * (b[d2] - y4));
    if (t1 && t1 <= t && a[t1] < y4) ans = min(ans, y4 - y3 + vt);
    t1--;
    if (t1 && t1 <= t) ans = min(ans, y4 - y3 + vt + 2 * (y3 - a[t1]));
    if (t2 && t2 <= t) ans = min(ans, y4 - y3 + vt + 2 * (a[t2] - y4));
    if (x3 == x4)
      printf("%d\n", len);
    else
      printf("%d\n", ans);
  }
}
