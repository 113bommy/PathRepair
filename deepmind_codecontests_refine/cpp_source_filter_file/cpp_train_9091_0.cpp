#include <bits/stdc++.h>
using namespace std;
int dblcmp(double a, double b) {
  if (fabs(a - b) < 1e-8) {
    return 0;
  }
  return a < b ? -1 : 1;
}
int main() {
  double x1, y1, r1;
  double x2, y2, r2;
  while (cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2) {
    double dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double rmax = max(r1, r2);
    double rmin = min(r1, r2);
    if (dblcmp(dis, r1 + r2) > 0) {
      printf("%.10lf\n", (dis - r1 - r2) / 2);
      continue;
    } else if (dblcmp(rmax - rmin, dis) < 0 && dblcmp(dis, r1 + r2) < 0) {
      printf("%.10lf\n", 0.0);
    } else {
      printf("%.10lf\n", (rmax - dis - rmin) / 2);
    }
  }
  return 0;
}
