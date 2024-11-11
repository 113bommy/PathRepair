#include <bits/stdc++.h>
using namespace std;
int a, v, l, d, w;
int main() {
  while (cin >> a >> v >> l >> d >> w) {
    double ans = 0.0;
    if (v <= w) {
      double l2 = (1.0 * v * v) / (2.0 * a);
      if (l2 < 1.0 * l) {
        ans += (1.0 * l - l2) / (1.0 * v);
        ans += (1.0 * v) / (1.0 * a);
      } else {
        ans = sqrt(2.0 * l / (1.0 * a));
      }
    } else {
      double l3 = (1.0 * w * w) / (2.0 * a);
      if (l3 >= 1.0 * d) {
        double l2 = (1.0 * v * v) / (2.0 * a);
        if (l2 < 1.0 * l) {
          ans += (1.0 * l - 1.0 * l2) / (1.0 * v);
          ans += (1.0 * v) / (1.0 * a);
        } else {
          ans = sqrt(2.0 * l / (1.0 * a));
        }
      } else {
        double x = (1.0 * w * w + 2.0 * a * d) / (4.0 * a);
        double v1 = sqrt(2.0 * a * x);
        if (v1 > 1.0 * v) {
          ans += (1.0 * v) / (1.0 * a);
          double l5 = (1.0 * v * v - 1.0 * w * w) / (2.0 * a);
          ans += (1.0 * v - 1.0 * w) / (1.0 * a);
          ans += (1.0 * d - l5 - 1.0 * v * v / (2.0 * a)) / (1.0 * v);
        } else {
          ans += (2.0 * v1 - 1.0 * w) / (1.0 * a);
        }
        double l4 = (1.0 * v * v - 1.0 * w * w) / (2.0 * a);
        if (l4 >= 1.0 * (l - d)) {
          ans += (sqrt(2.0 * a * (l - d) + 1.0 * w * w) - 1.0 * w) / (1.0 * a);
        } else {
          ans += (1.0 * v - 1.0 * w) / (1.0 * a);
          ans += (1.0 * (l - d) - 1.0 * l4) / (1.0 * v);
        }
      }
    }
    printf("%.10f\n", ans);
  }
  return (0);
}
