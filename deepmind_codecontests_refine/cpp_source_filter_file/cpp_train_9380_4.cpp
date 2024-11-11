#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int n, d1, d2, ans;
bool good = true;
inline int dcmp(double x) {
  if (abs(x) <= eps) return 0;
  return x > 0 ? 1 : -1;
}
inline double get(int x1, int x2, int x3, int x4, double t) {
  return (x2 - x1) * t + (x4 - x3) * t;
}
void check(double dis2) {
  if (dcmp(dis2 - ((d1) * (d1))) <= 0 && good)
    ans++, good = false;
  else if (dcmp(dis2 - ((d2) * (d2))) > 0)
    good = true;
}
int main() {
  scanf("%d%d%d", &n, &d1, &d2);
  int px1, py1, px2, py2;
  for (int(i) = (0); (i) <= ((n)-1); (i)++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (i) {
      double lo = 0, hi = 1;
      for (int(_) = (0); (_) <= ((70) - 1); (_)++) {
        double m1 = (lo * 2 + hi) / 3, m2 = (lo + hi * 2) / 3;
        double xm1 = get(px1, px2, x1, x2, m1), ym1 = get(py1, py2, y1, y2, m1);
        double xm2 = get(px1, px2, x1, x2, m2), ym2 = get(py1, py2, y1, y2, m2);
        if (((xm1) * (xm1)) + ((ym1) * (ym1)) >
            ((xm2) * (xm2)) + ((ym2) * (ym2)))
          lo = m1;
        else
          hi = m2;
      }
      double xm = get(px1, px2, x1, x2, lo), ym = get(py1, py2, y1, y2, lo);
      check(((xm) * (xm)) + ((ym) * (ym)));
    }
    int dis2 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    check(dis2);
    px1 = x1, px2 = x2, py1 = y1, py2 = y2;
  }
  printf("%d", ans);
}
