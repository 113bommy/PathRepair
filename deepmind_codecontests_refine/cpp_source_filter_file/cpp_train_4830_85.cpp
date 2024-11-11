#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
int n;
double ang, len;
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void Out() { printf("%.5lf %.5lf\n", x, y); }
};
Point p[105];
double dist(Point u, Point v) {
  return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  if (n <= 4) {
    printf("No solution\n");
    return 0;
  }
  if (n >= 98) {
    ang = 2.0 * pi / n;
    double len = 900.0;
    p[1] = Point(len * cos(ang / 2.0), len * sin(ang / 2.0));
    p[2] = Point(len * cos(ang / 2.0 * 3), len * sin(ang / 2.0 * 3));
    while (true) {
      double a = ang / 2.0 * 3, Edge = dist(p[1], p[2]);
      for (int i = 3; i <= n; i++) {
        double tmp =
            (double)((((rand()) + rand())) * (len / (n * 10))) / (100000000.0);
        if (tmp < 0.001) tmp += 0.001;
        Edge -= tmp;
        double x0 = cos(a), y0 = sin(a);
        a += ang;
        double x1 = cos(a), y1 = sin(a);
        tmp = Edge / dist(Point(x0, y0), Point(x1, y1));
        p[i] =
            Point(tmp * (x1 - x0) + p[i - 1].x, tmp * (y1 - y0) + p[i - 1].y);
      }
      if (p[n - 1].x >= p[1].x) continue;
      p[n].y = p[n].y + (p[n].y - p[n - 1].y) * (p[1].x - p[n].x) /
                            (p[n].x - p[n - 1].x);
      p[n].x = p[1].x;
      if (p[n].y > p[1].y) continue;
      double L1 = dist(p[n - 1], p[n]), L2 = dist(p[n], p[1]);
      bool flag = true;
      for (int i = 2; i < n; i++) {
        double len = dist(p[i], p[i - 1]);
        if ((fabs(len - L1) < 0.001) || (fabs(len - L2) < 0.001)) {
          flag = true;
          break;
        }
      }
      if (!flag) continue;
      if (dist(p[n], p[1]) > 1.0) {
        for (int i = 1; i <= n; i++) p[i].Out();
        break;
      }
    }
    return 0;
  }
  ang = 2.0 * pi / n;
  double len;
  if (n >= 40)
    len = 900.0;
  else
    len = 200.0;
  p[1] = Point(len * cos(ang / 2.0), len * sin(ang / 2.0));
  p[2] = Point(len * cos(ang / 2.0 * 3), len * sin(ang / 2.0 * 3));
  while (true) {
    double a = ang / 2.0 * 3, Edge = dist(p[1], p[2]);
    for (int i = 3; i <= n; i++) {
      double tmp =
          (double)(((rand()) + rand())) * (len / (n * 10)) / (10000000.0);
      if (tmp < 0.001) tmp += 0.001;
      Edge -= tmp;
      double x0 = cos(a), y0 = sin(a);
      a += ang;
      double x1 = cos(a), y1 = sin(a);
      tmp = Edge / dist(Point(x0, y0), Point(x1, y1));
      p[i] = Point(tmp * (x1 - x0) + p[i - 1].x, tmp * (y1 - y0) + p[i - 1].y);
    }
    if (p[n - 1].x >= p[1].x) continue;
    p[n].y = p[n].y +
             (p[n].y - p[n - 1].y) * (p[1].x - p[n].x) / (p[n].x - p[n - 1].x);
    p[n].x = p[1].x;
    if (p[n].y > p[1].y) continue;
    double L1 = dist(p[n - 1], p[n]), L2 = dist(p[n], p[1]);
    bool flag = true;
    for (int i = 2; i < n; i++) {
      double len = dist(p[i], p[i - 1]);
      if ((fabs(len - L1) < 0.001) || (fabs(len - L2) < 0.001)) {
        flag = true;
        break;
      }
    }
    if (!flag) continue;
    if (dist(p[n], p[1]) > 1.0) {
      for (int i = 1; i <= n; i++) p[i].Out();
      break;
    }
  }
  return 0;
}
