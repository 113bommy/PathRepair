#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-10;
struct Point {
  double x;
  double y;
  double z;
};
double getDist(Point a, Point b) {
  double dx = fabs(a.x - b.x);
  double dy = fabs(a.y - b.y);
  double dz = fabs(a.z - b.z);
  return sqrt(dx * dx + dy * dy + dz * dz);
}
double getDtime(Point a, Point b, double v) { return getDist(a, b) / v; }
double solve(Point start, double vp, double vs, double t0, Point p0, Point p1,
             Point &p) {
  if (getDtime(start, p0, vp) < t0 + EPS) {
    p = p0;
    return t0;
  }
  double dx = p1.x - p0.x;
  double dy = p1.y - p0.y;
  double dz = p1.z - p0.z;
  {
    double l = 0.0;
    double r = 1.0;
    for (int i = 0; i < (200); ++i) {
      double mid = (l + r) / 2.0;
      Point tp = {p0.x + mid * dx, p0.y + mid * dy, p0.z + mid * dz};
      double t1 = getDtime(start, tp, vp);
      double t2 = getDtime(p0, tp, vs) + t0;
      if (t1 > t2)
        l = mid;
      else
        r = mid;
    }
    double mid = (l + r) / 2.0;
    Point tp = {p0.x + mid * dx, p0.y + mid * dy, p0.z + mid * dz};
    double t1 = getDtime(start, tp, vp);
    double t2 = getDtime(p0, tp, vs) + t0;
    if (fabs(t1 - t2) < EPS) {
      p = tp;
      return t1;
    }
  }
  {
    double l = 0.0;
    double r = 1.0;
    for (int i = 0; i < (200); ++i) {
      double mid = (l + r) / 2.0;
      Point tp = {p0.x + mid * dx, p0.y + mid * dy, p0.z + mid * dz};
      double t1 = getDtime(start, tp, vp);
      double t2 = getDtime(p0, tp, vs) + t0;
      if (t1 < t2)
        l = mid;
      else
        r = mid;
    }
    double mid = (l + r) / 2.0;
    Point tp = {p0.x + mid * dx, p0.y + mid * dy, p0.z + mid * dz};
    double t1 = getDtime(start, tp, vp);
    double t2 = getDtime(p0, tp, vs) + t0;
    if (fabs(t1 - t2) < EPS) {
      p = tp;
      return t1;
    }
  }
  return DBL_MAX;
}
int main(void) {
  int n;
  cin >> n;
  vector<Point> points(n + 1);
  double vp, vs;
  Point start;
  for (int i = 0; i < (n + 1); ++i) {
    cin >> points[i].x >> points[i].y >> points[i].z;
  }
  cin >> vp >> vs;
  cin >> start.x >> start.y >> start.z;
  vector<double> times(n + 1);
  times[0] = 0.0;
  for (int i = 0; i < (n); ++i) {
    times[i + 1] = times[i] + getDtime(points[i + 1], points[i], vs);
  }
  bool OK = false;
  for (int i = 0; i < (n); ++i) {
    Point p;
    double t = solve(start, vp, vs, times[i], points[i], points[i + 1], p);
    if (t != DBL_MAX) {
      printf("YES\n");
      printf("%.10f\n", t);
      printf("%.10f %.10f %.10f\n", p.x, p.y, p.z);
      OK = true;
      break;
    }
  }
  if (!OK) printf("NO\n");
  return 0;
}
