#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
struct Point {
  double x, y, z;
  Point(double x_ = 0, double y_ = 0, double z_ = 0) : x(x_), y(y_), z(z_) {}
};
Point operator-(const Point& a, const Point& b) {
  return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}
Point operator+(const Point& a, const Point& b) {
  return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}
Point operator*(const Point& a, const double& k) {
  return Point(a.x * k, a.y * k, a.z * k);
}
double operator~(const Point& a) {
  return ((a.x) * (a.x)) + ((a.y) * (a.y)) + ((a.z) * (a.z));
}
Point a, v;
double R;
double get(Point p, double R_) {
  double rad = R + R_;
  double l = 0, r = 1e20;
  while (r - l > eps) {
    double ll = l + (r - l) * 19.0 / 40.0;
    double rr = l + (r - l) * 21.0 / 40.0;
    if (~((a + v * ll) - p) < ~((a + v * rr) - p)) {
      r = rr;
    } else {
      l = ll;
    }
  }
  if (~((a + v * r) - p) > ((rad) * (rad)) + eps) {
    return 1e100;
  }
  l = 0;
  while (r - l > eps) {
    double ll = (r + l) / 2;
    if (~((a + v * ll) - p) < ((rad) * (rad))) {
      r = ll;
    } else {
      l = ll;
    }
  }
  if (l < eps) {
    r = r;
  }
  return l;
}
int main() {
  double mn = 1e100;
  int n;
  cin >> a.x >> a.y >> a.z >> v.x >> v.y >> v.z >> R;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    Point o;
    double r;
    int m;
    cin >> o.x >> o.y >> o.z >> r >> m;
    for (int i = 0; i < m; ++i) {
      Point p;
      cin >> p.x >> p.y >> p.z;
      p = p + o;
      mn = min(mn, get(p, 0));
    }
    mn = min(mn, get(o, r));
  }
  if (mn < 1e15) {
    printf("%.10lf\n", mn);
  } else {
    cout << -1 << endl;
  }
  return 0;
}
