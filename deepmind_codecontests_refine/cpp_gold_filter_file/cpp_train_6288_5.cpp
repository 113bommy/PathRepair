#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
} point[400];
double across(Point a, Point b, Point c) {
  return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2;
}
int main() {
  int n;
  double ans = 0, lmax, rmax;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> point[i].x >> point[i].y;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      lmax = 0;
      rmax = 0;
      for (int k = 1; k < n; k++) {
        if (k == i || k == j) {
          continue;
        }
        double s = across(point[i], point[j], point[k]);
        if (s < 0) {
          lmax = max(lmax, -s);
        } else {
          rmax = max(rmax, s);
        }
      }
      if (lmax == 0 || rmax == 0) {
        continue;
      }
      ans = max(ans, (lmax + rmax));
    }
  }
  printf("%lf\n", ans);
  return 0;
}
