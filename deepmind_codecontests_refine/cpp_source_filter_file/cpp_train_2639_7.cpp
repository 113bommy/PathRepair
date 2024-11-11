#include <bits/stdc++.h>
using namespace std;
typedef struct {
  double x, y;
} Point;
typedef struct {
  Point p1, p2;
} Line;
const int MAXM = 10;
const double eps = 1e-6;
const double PI = acos(-1.0);
Point p[MAXM], o;
Line l[MAXM];
int dblcmp(double d) {
  if (fabs(d) < eps)
    return 0;
  else
    return (d > 0) ? 1 : -1;
}
double cross(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double cross(Point a, Point b, Point c, Point d) {
  return (b.x - a.x) * (d.y - c.y) - (d.x - c.x) * (b.y - a.y);
}
double dis(Point a, Point b) {
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
void Line_intersection(Line L1, Line L2) {
  double k = cross(L2.p1, L2.p2, L1.p1) / cross(L1.p1, L1.p2, L2.p1, L2.p2);
  o.x = L1.p1.x + k * (L1.p2.x - L1.p1.x);
  o.y = L1.p1.y + k * (L1.p2.y - L1.p1.y);
}
int main() {
  int i;
  double k, b;
  for (i = 0; i < 3; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  p[3].x = (p[0].x + p[1].x) * 0.5;
  p[3].y = (p[0].y + p[1].y) * 0.5;
  p[4].x = (p[0].x + p[2].x) * 0.5;
  p[4].y = (p[0].y + p[2].y) * 0.5;
  if (dblcmp(p[0].x - p[1].x) == 0) {
    l[0].p1 = l[0].p2 = p[3];
    l[0].p2.x += 1.0;
  } else if (dblcmp(p[0].y - p[1].y) == 0) {
    l[0].p1 = l[0].p2 = p[3];
    l[0].p2.y += 1.0;
  } else {
    l[0].p1 = p[3];
    k = (p[1].x - p[0].x) / (p[1].y - p[0].y) * -1.0;
    b = p[3].y - k * p[3].x;
    l[0].p2.x = p[3].x + 1.0;
    l[0].p2.y = k * (p[3].x + 1.0) + b;
  }
  if (dblcmp(p[0].x - p[2].x) == 0) {
    l[1].p1 = l[1].p2 = p[4];
    l[1].p2.x += 1.0;
  } else if (dblcmp(p[0].y - p[2].y) == 0) {
    l[1].p1 = l[1].p2 = p[4];
    l[1].p2.y += 1.0;
  } else {
    l[1].p1 = p[4];
    k = (p[2].x - p[0].x) / (p[2].y - p[0].y) * -1.0;
    b = p[4].y - k * p[4].x;
    l[1].p2.x = p[4].x + 1.0;
    l[1].p2.y = k * (p[4].x + 1.0) + b;
  }
  Line_intersection(l[0], l[1]);
  double r, d1, d2;
  r = dis(o, p[0]);
  d1 = dis(p[0], p[1]);
  d2 = dis(p[0], p[2]);
  double arg1, arg2;
  arg1 = asin(d1 * 0.5 / r) * 2.0;
  arg2 = asin(d2 * 0.5 / r) * 2.0;
  double arg;
  for (i = 3; i <= 100; i++) {
    arg = 2.0 * PI / (double)(i);
    if ((dblcmp(arg1 / arg - (int)(arg1 / arg)) == 0 ||
         dblcmp(arg1 / arg - (int)(arg1 / arg) - 1.0) == 0) &&
        (dblcmp(arg2 / arg - (int)(arg2 / arg)) == 0 ||
         dblcmp(arg2 / arg - (int)(arg2 / arg) - 1.0) == 0)) {
      double c = sqrt(2.0 * r * r * (1.0 - cos(arg)));
      double w = (r + r + c) / 2;
      double s = sqrt(w * (w - r) * (w - r) * (w - c)) * i;
      printf("%lf\n", s);
      break;
    }
  }
  return 0;
}
