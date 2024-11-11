#include <bits/stdc++.h>
using namespace std;
int x, y, s, t, t1, v, k, a, b, c, d, c1, d1;
inline double P(double x) { return x * x; }
int main() {
  while (~scanf("%d%d%d%d", &x, &y, &s, &t)) {
    scanf("%d%d", &v, &t1);
    scanf("%d%d", &c, &d);
    scanf("%d%d", &c1, &d1);
    double x1 = x + t1 * c, y1 = y + t1 * d;
    double dis = sqrt(P(s - x1) + P(t - y1));
    if (dis / v <= t1) {
      double l = 0, r = t1;
      for (int i = 1; i <= 200; i++) {
        double mid = (l + r) / 2;
        x1 = s - (x + mid * c);
        y1 = t - (y + mid * d);
        dis = sqrt(P(x1) + P(y1));
        double t2 = dis / v;
        t2 <= mid ? r = mid : l = mid;
      }
      printf("%.14f\n", l);
    } else {
      x1 = x + t1 * c, y1 = y + t1 * d;
      double l = t1, r = 10000000;
      for (int i = 1; i <= 200; i++) {
        double mid = (l + r) / 2;
        double x2 = s - (x1 + (mid - t1) * c1);
        double y2 = t - (y1 + (mid - t1) * d1);
        dis = sqrt(P(x2) + P(y2));
        double t2 = dis / v;
        t2 <= mid ? r = mid : l = mid;
      }
      printf("%.14f\n", l);
    }
  }
  return 0;
}
