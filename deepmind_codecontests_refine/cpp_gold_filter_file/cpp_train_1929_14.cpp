#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x;
  double y;
  Point() {}
  Point(double x_, double y_) : x(x_), y(y_) {}
  Point operator*(const double &t) const { return Point(x * t, y * t); }
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
};
int main() {
  Point p[8];
  Point v[4];
  double V;
  double a;
  double b;
  double c;
  double d;
  scanf("%lf%lf%lf%lf", &p[0].x, &p[0].y, &v[0].x, &v[0].y);
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  V = sqrt(v[0].x * v[0].x + v[0].y * v[0].y);
  v[0].x = v[0].x / V;
  v[0].y = v[0].y / V;
  v[1].x = -v[0].y;
  v[1].y = v[0].x;
  v[2].x = -v[0].x;
  v[2].y = -v[0].y;
  v[3].x = v[0].y;
  v[3].y = -v[0].x;
  double a2 = a / 2.0;
  double c2 = c / 2.0;
  p[1] = p[0] + v[0] * b;
  p[2] = p[0] + v[1] * a2;
  p[3] = p[0] + v[1] * c2;
  p[4] = p[3] + v[2] * d;
  p[5] = p[4] + v[3] * c;
  p[6] = p[0] + v[3] * c2;
  p[7] = p[0] + v[3] * a2;
  for (int i = 1; i <= 7; i++) {
    printf("%.10lf %.10lf\n", p[i].x, p[i].y);
  }
  return 0;
}
