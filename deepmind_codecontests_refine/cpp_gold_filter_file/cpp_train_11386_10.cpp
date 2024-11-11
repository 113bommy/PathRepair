#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
};
double xmult(point p1, point p2, point p0) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double distance(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double disptoline(point p, point l1, point l2) {
  return fabs(xmult(p, l1, l2)) / distance(l1, l2);
}
int main() {
  double y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  point a, b, c;
  double x = (yw - r - y1 - r) * xb / (yw - r - yb + yw - r - y1 - r);
  a.x = 0;
  a.y = y2;
  b.x = 0;
  b.y = y1 + r;
  c.x = x;
  c.y = yw - r;
  double d = disptoline(a, b, c);
  if (d < r) {
    puts("-1");
  } else {
    printf("%.9lf\n", x);
  }
}
