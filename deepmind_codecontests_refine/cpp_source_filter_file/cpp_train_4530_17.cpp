#include <bits/stdc++.h>
const double pi = acos(-1.0);
int main() {
  int n, r, v;
  scanf("%d%d%d", &n, &r, &v);
  double c = 2 * pi * r;
  double t = c / v;
  int s, f;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &s, &f);
    double cnt = (f - s) / c;
    int ccnt = (int)cnt;
    double ti = t * ccnt;
    double res = (cnt - ccnt) * 2 * pi;
    double left = pi, right = 2 * pi;
    while (right - left >= 1e-12) {
      double mid = (left + right) / 2;
      if (2 * mid - 2 * pi - 2 * sin(mid) - res > 0)
        right = mid;
      else
        left = mid;
    }
    ti = ti + 2 * (left - pi) * r / v;
    printf("%.12lf\n", ti);
  }
  return 0;
}
