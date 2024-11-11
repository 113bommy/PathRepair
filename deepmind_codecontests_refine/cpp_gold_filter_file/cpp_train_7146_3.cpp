#include <bits/stdc++.h>
using namespace std;
double r, X1, Y1, X2, Y2;
double find_y(double x) {
  double m = ((abs(Y1 - Y2)) * (x - X1)) / (abs(X1 - X2));
  double y = m + Y1;
  return y;
}
double find_x(double y) {
  double m = ((abs(X1 - X2)) * (y - Y1)) / (abs(Y1 - Y2));
  double x = m + X1;
  return x;
}
int get_dir(double x, double y) {
  double val = ((x - X1) * (x - X1)) + ((y - Y1) * (y - Y1));
  double rad = r * r;
  if (val > rad) return 2;
  if (val <= rad) return 1;
}
double bin_sear(double lo, double hi, int stat) {
  int cnt = 2000;
  double mid;
  while (cnt--) {
    mid = (lo + hi) / 2.0;
    double x, y;
    if (stat == 0) {
      x = mid;
      y = find_y(x);
    } else {
      y = mid;
      x = find_x(y);
    }
    int dir = get_dir(x, y);
    if (dir == 1)
      lo = mid;
    else
      hi = mid;
  }
  return mid;
}
double find_dis(double x1, double y1, double x2, double y2) {
  double val = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
  val = sqrt(val);
  return val;
}
int main() {
  scanf("%lf %lf %lf %lf %lf", &r, &X1, &Y1, &X2, &Y2);
  double dis = find_dis(X1, Y1, X2, Y2);
  if (dis >= r) {
    printf("%.8lf %.8lf %.8lf\n", X1, Y1, r);
    return 0;
  }
  if (dis == 0) {
    printf("%.8lf %.8lf %.8lf\n", X1 + (r / 2.0), Y1, r / 2.0);
    return 0;
  }
  double m1 = find_dis(X1, Y1, X2, Y2) + r;
  double m2 = r;
  double xx1 = (m1 * X1 - m2 * X2) / (m1 - m2);
  double yy1 = (m1 * Y1 - m2 * Y2) / (m1 - m2);
  xx1 = (xx1 + X2) / 2.0;
  yy1 = (yy1 + Y2) / 2.0;
  double dis1 = m1 / 2;
  printf("%.8lf %.8lf %.8lf\n", xx1, yy1, dis1);
}
