#include <bits/stdc++.h>
using namespace std;
int n, d, a[200010];
const double pi = 3.14159265358979323846264338327950288;
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int m;
  scanf("%d", &m);
  while (m--) {
    int x;
    scanf("%d", &x);
    int p = lower_bound(a + 1, a + n + 1, x) - a;
    if (x > a[n]) {
      printf("%.12lf\n", pi / 2);
      continue;
    }
    int e = a[p] - x;
    if (p > 1) e = min(e, x - a[p - 1] - 1);
    int l = p - 1, r = p;
    int f = -1;
    while (l && r <= n) {
      if (x - a[l] - 2 > 2 * e) break;
      while (r <= n && a[r] + a[l] + 2 < 2 * x) r++;
      if (r <= n) {
        if (a[r] + a[l] == 2 * x) {
          f = a[r] - x;
          break;
        }
        if (a[r] + a[l] + 1 == 2 * x) {
          f = a[r] - x;
          break;
        }
        if (a[r] + a[l] + 2 == 2 * x) {
          f = a[r] + 1 - x;
          break;
        }
      }
      l--;
    }
    double ans;
    if (e == 0)
      ans = pi / 2;
    else
      ans = atan(1.0 / e);
    if (f >= 0) {
      if (f == 0)
        ans = max(ans, pi / 2);
      else
        ans = max(ans, 2 * atan(1.0 / f));
    }
    printf("%.12lf\n", ans);
  }
}
