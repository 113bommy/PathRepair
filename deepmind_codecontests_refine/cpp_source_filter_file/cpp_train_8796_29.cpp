#include <bits/stdc++.h>
double solve(double y) {
  double lo = 0, hi = 3.14159265359;
  for (int i = 0; i < 50; i++) {
    double mid = (lo + hi) / 2;
    if (mid + sin(mid) < y) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}
int main() {
  int n;
  double r, v;
  scanf("%d %lf %lf", &n, &r, &v);
  double period = 2 * 3.14159265359 * r;
  double periodtime = period / v;
  for (int i = 0; i < n; i++) {
    double x, y;
    scanf("%lf %lf", &x, &y);
    double dist = y - x;
    double cycles = floor(dist / period);
    double ans = cycles * periodtime;
    dist -= period * cycles;
    double c = dist / period * 3.14159265359;
    double theta = solve(c);
    ans += theta * periodtime / 3.14159265359;
    printf("%.8lf\n", ans);
  }
}
