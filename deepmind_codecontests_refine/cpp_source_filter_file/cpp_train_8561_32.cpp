#include <bits/stdc++.h>
using namespace std;
int n;
double x[25005], y[25005], dx[25005], dy[25005], s[25005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf %lf %lf %lf", &x[i], &y[i], &dx[i], &dy[i], &s[i]);
  }
  double mn = 1000000000000000000;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      double x2 = x[j];
      double x1 = x[i];
      double y2 = y[j];
      double y1 = y[i];
      double dx2 = dx[j];
      double dx1 = dx[i];
      double dy2 = dy[j];
      double dy1 = dy[i];
      double s2 = s[j];
      double s1 = s[i];
      if (dx1 * dy2 == dy1 * dx2) {
        if ((x2 - x1) * dy2 == (y2 - y1) * dx2) {
          if ((x1 - x2) / dx1 >= 0 && (x2 - x1) / dx2 >= 0) {
            double tt =
                sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / (s1 + s2);
            mn = min(mn, tt);
          }
          if ((x1 - x2) / dx1 >= 0 && (x2 - x1) / dx2 < 0) {
            double tt =
                sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / (s2);
            mn = min(mn, tt);
          }
          if ((x1 - x2) / dx1 < 0 && (x2 - x1) / dx2 >= 0) {
            double tt =
                sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / (s1);
            mn = min(mn, tt);
          }
        } else {
          continue;
        }
      }
      double a1 = ((x2 - x1) * dy2 - (y2 - y1) * dx2) / (dx1 * dy2 - dy1 * dx2);
      double a2 = ((x2 - x1) * dy1 - (y2 - y1) * dx1) / (dx1 * dy2 - dy1 * dx2);
      if (a1 <= 0 && a2 <= 0) {
        continue;
      }
      double t = max((fabs(a1) * sqrt(dx1 * dx1 + dy1 * dy1)) / s1,
                     (fabs(a2) * sqrt(dx2 * dx2 + dy2 * dy2)) / s2);
      mn = min(mn, t);
    }
  }
  if (mn == 1000000000000000000) {
    printf("No show :(\n");
  } else {
    printf("%.15lf\n", mn);
  }
  return 0;
}
