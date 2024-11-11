#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
struct point {
  double x, y, z;
  point() {}
  point(double x, double y, double z) : x(x), y(y), z(z) {}
  void get() { scanf("%lf%lf%lf", &x, &y, &z); }
  void out() { printf("%lf %lf %lf\n", x + eps, y + eps, z + eps); }
  point operator-(const point &p) const {
    return point(x - p.x, y - p.y, z - p.z);
  }
  point operator*(const double &v) const { return point(x * v, y * v, z * v); }
  double operator*(const point &p) const { return x * p.x + y * p.y + z * p.z; }
  point operator+(const point &p) const {
    return point(x + p.x, y + p.y, z + p.z);
  }
  bool operator<(const point &p) const {
    return x < p.x || x == p.x && y < p.y;
  }
  double abs2() { return (*this) * (*this); }
  double abs() { return sqrt(abs2()); }
} p[110];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) p[i].get();
    sort(p, p + n);
    point o = (p[0] + p[n - 1]) * .5;
    double ans = 1e10, step = (p[n - 1] - p[0]).abs();
    while (step > eps) {
      double max_d = 0;
      int id;
      for (int i = 0; i < n; i++) {
        double dis = (p[i] - o).abs2();
        if (dis > max_d) {
          id = i;
          max_d = dis;
        }
      }
      if (max_d < ans) ans = max_d;
      if (fabs(max_d) < eps) break;
      o = o + (p[id] - o) * (step / sqrt(max_d));
      step *= 0.98;
    }
    o.out();
  }
  return 0;
}
