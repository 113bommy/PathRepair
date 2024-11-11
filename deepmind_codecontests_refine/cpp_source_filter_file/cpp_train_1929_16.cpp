#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
int dcmp(double x) { return fabs(x) <= eps ? 0 : (x > 0 ? 1 : -1); }
double px, py, vx, vy, a, b, c, d;
void Print(double x, double y) {
  double d = sqrt(vx * vx + vy * vy);
  double s = vx / d, c = vy / d;
  double gx = x * c - y * s;
  double gy = x * s + y * c;
  printf("%.9f %.9f\n", gx + px, gy + py);
}
int main() {
  scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &px, &py, &vx, &vy, &a, &b, &c, &d);
  Print(0, b);
  Print(-a / 2.0, 0);
  Print(-c / 2.0, 0);
  Print(-c / 2.0, -d);
  Print(c / 2.0, -d);
  Print(c / 2.0, 0);
  Print(a / 2.0, 0);
  return 0;
}
