#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
double f(double x) { return 2 * cos((0.5 - x) * pi); }
int main() {
  int n, r, v;
  scanf("%d%d%d", &n, &r, &v);
  for (int i = 1; i <= n; i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    t -= s;
    int k = int(t / 2 / pi / r);
    double rest = t - k * 2 * pi * r;
    double ll = 0, rr = 1;
    for (int j = 1; j <= 100; j++) {
      double mid = (ll + rr) / 2;
      if (mid * 2 * pi * r + f(mid) * r < rest)
        ll = mid;
      else
        rr = mid;
    }
    double ss = (k + (ll + rr) / 2) * 2 * pi * r;
    printf("%.10lf\n", ss / v);
  }
  return 0;
}
