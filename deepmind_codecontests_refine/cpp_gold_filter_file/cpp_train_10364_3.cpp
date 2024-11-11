#include <bits/stdc++.h>
using namespace std;
double n, dist, v1, v2, k;
int g, n1, k1;
int check(double mid) {
  double tim = 0, x, y;
  for (int i = 0; i < g; i++) {
    x = (dist - (v1 * mid)) / (v2 - v1);
    tim += x;
    if (i + 1 < g) {
      y = (x * (v2 - v1)) / (v1 + v2);
      tim += y;
    }
  }
  if (tim <= mid)
    return 1;
  else
    return 0;
}
double solve() {
  double l, h, mid;
  l = 0, h = dist / v1;
  while (h - l >= 0.0000005) {
    mid = (h + l) / 2;
    if (check(mid) == 1)
      h = mid;
    else
      l = mid;
  }
  return l;
}
int main() {
  scanf("%d%lf%lf%lf%d", &n1, &dist, &v1, &v2, &k1);
  g = n1 / k1;
  n = n1;
  k = k1;
  if (n1 % k1 != 0) g++;
  double ans = solve();
  printf("%.6lf", ans);
  return 0;
}
