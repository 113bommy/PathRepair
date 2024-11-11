#include <bits/stdc++.h>
using namespace std;
double sqr(double x) { return x * x; }
double getDis(long long x1, long long y1, long long x2, long long y2) {
  return sqrt((double)sqr(x1 - x2) + sqr(y1 - y2));
}
int n, xp, yp;
int x[100005], y[100005];
double getC(double r) { return r * r * 3.14159265358979323846; }
struct point {
  double x, y;
  point() {
    x = 0;
    y = 0;
  }
  point(double a, double b) : x(a), y(b) {}
};
struct Line {
  point p1, p2;
  double A, B, C;
  Line() {}
  Line(double xx1, double yy1, double xx2, double yy2) {
    p1 = point(xx1, yy1), p2 = point(xx2, yy2);
    A = p1.y - p2.y, B = p2.x - p1.x, C = -(A * p1.x + B * p1.y);
  }
  Line(point t1, point t2) {
    p1 = t1, p2 = t2;
    A = p1.y - p2.y, B = p2.x - p1.x, C = -(A * p1.x + B * p1.y);
  }
  double getDis(double x, double y) {
    return abs(A * x + B * y + C) / sqrt(A * A + B * B);
  }
};
double dot(double v1x, double v1y, double v2x, double v2y) {
  return v1x * v2x + v1y * v2y;
}
int main() {
  scanf("%d%d%d", &n, &xp, &yp);
  for (int i = 0; i < n; ++i) scanf("%d %d", x + i, y + i);
  double mx = -1, mn = 1ll << 60;
  for (int i = 0; i < n; ++i) {
    double d = getDis(xp, yp, x[i], y[i]);
    mx = max(mx, d);
    mn = min(mn, d);
  }
  for (int i = 0; i < n; ++i) {
    double x1 = x[i], y1 = y[i];
    double x2 = x[(i + 1) % n], y2 = y[(i + 1) % n];
    double v1 = dot(xp - x1, yp - y1, x2 - x1, y2 - y1);
    double v2 = dot(x2 - x1, y2 - y1, x2 - x1, y2 - y1);
    if (0.0 - 1e-9 < v1 && v1 < v2 + 1e-9) {
      Line line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
      mn = min(mn, line.getDis(xp, yp));
    }
  }
  printf("%.20lf", (mx * mx - mn * mn) * 3.14159265358979323846);
}
