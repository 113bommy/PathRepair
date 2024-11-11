#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, x, y, T, ans, big, cas, num, len;
bool flag;
double a[200005];
double chk(double x) {
  double pre, pre2, ans, ans2;
  ans = 0;
  ans2 = 0;
  pre = 0;
  pre2 = 0;
  for (int i = 1; i <= n; i++) {
    pre += a[i] - x;
    ans = max(ans, fabs(pre));
    pre = max(pre, 0.0);
    pre2 += a[i] - x;
    ans2 = max(ans2, fabs(pre2));
    pre2 = min(pre2, 0.0);
  }
  return max(fabs(ans), fabs(ans2));
}
int main() {
  scanf("%d", &n);
  double mx = -0x3fffffff, mi = 0x3fffffff;
  for (i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
    mx = max(mx, a[i]);
    mi = min(mi, a[i]);
  }
  double l = mi, r = mx;
  while (true) {
    double m1 = (r + 2 * l) / 3;
    double m2 = (2 * r + l) / 3;
    double c1 = chk(m1), c2 = chk(m2);
    if (fabs(m1 - m2) < 1e-7 && fabs(c1 - c2) < 1e-7) break;
    if (c1 < c2)
      r = (2 * r + l) / 3;
    else
      l = (r + 2 * l) / 3;
  }
  printf("%.12lf\n", chk(l));
  return 0;
}
