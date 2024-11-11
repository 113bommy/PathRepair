#include <bits/stdc++.h>
using namespace std;
const double G = 9.8;
const double kEps = 1e-6;
const int kNMax = 10010, kMMax = 100010;
double V;
int n;
int sgn(double x) {
  if (fabs(x) < kEps) return 0;
  return x > 0 ? 1 : -1;
}
struct Point {
  double x, y;
  Point() {}
  Point(double xx, double yy) : x(xx), y(yy) {}
} ans[kNMax];
struct Bomb {
  double agl;
  double a, b;
  int id;
  void init() {
    double k = 1.0 / (V * cos(agl));
    a = -G * k * k / 2;
    b = V * sin(agl) * k;
  }
  bool operator<(const Bomb &T) const { return agl < T.agl; }
} bomb[kNMax];
double calcGroundX(int i) {
  double t = 2 * sin(bomb[i].agl) * V / G;
  return t * cos(bomb[i].agl) * V;
}
double calcY(int i, double x) { return bomb[i].a * x * x + bomb[i].b * x; }
struct Wall {
  double x, y;
  bool operator<(const Wall &T) const { return x < T.x; }
} wall[kMMax];
int main() {
  scanf("%d%lf", &n, &V);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &bomb[i].agl);
    bomb[i].id = i;
    bomb[i].init();
  }
  sort(bomb, bomb + n);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%lf%lf", &wall[i].x, &wall[i].y);
  sort(wall, wall + m);
  for (int i = 0, j = 0; i < n; i++) {
    while (j < m && sgn(calcY(i, wall[j].x) - wall[j].y) > 0) j++;
    if (j == m || sgn(calcY(i, wall[j].x)) < 0) {
      ans[bomb[i].id] = Point(calcGroundX(i), 0);
    } else {
      ans[bomb[i].id] = Point(wall[j].x, calcY(i, wall[j].x));
    }
  }
  for (int i = 0; i < n; i++) printf("%.8lf %.8lf\n", ans[i].x, ans[i].y);
}
