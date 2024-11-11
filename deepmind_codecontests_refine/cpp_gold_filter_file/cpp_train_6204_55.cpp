#include <bits/stdc++.h>
using namespace std;
const int MX_SZ = 1e+5 + 42;
const int MAX = 1e+6 + 42;
const double EPS = 1e-12;
struct point {
  double x1, y1, x2, y2;
  point() {}
  void read() { cin >> x1 >> y1 >> x2 >> y2; }
};
point m;
inline bool inside(double x, double y) {
  return x < m.x2 and x > m.x1 and y < m.y2 and y > m.y1;
}
inline double get_tin(double x1, double x2, double mx1, double mx2) {
  double l = 0, r = MAX;
  while (fabs(l - r) > EPS) {
    double t = (l + r) / 2;
    double nx = x1 + t * x2;
    if ((x1 <= mx1 and nx <= mx1) or (x1 >= mx2 and nx >= mx2)) {
      l = t;
    } else {
      r = t;
    }
  }
  return r;
}
inline double get_tout(double x1, double x2, double mx1, double mx2) {
  double l = 0, r = MAX;
  while (fabs(l - r) > EPS) {
    double t = (l + r) / 2;
    double nx = x1 + t * x2;
    if ((x1 >= mx1 and x2 < 0 and nx <= mx1) or
        (x1 <= mx2 and x2 > 0 and nx >= mx2)) {
      r = t;
    } else {
      l = t;
    }
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  m.read();
  static point a[MX_SZ];
  static double tin[MX_SZ], tout[MX_SZ];
  for (int i = 0; i < n; ++i) {
    a[i].read();
    if ((a[i].x1 <= m.x1 and a[i].x2 <= 0) or
        (a[i].x1 >= m.x2 and a[i].x2 >= 0)) {
      cout << -1 << endl;
      return 0;
    }
    if ((a[i].y1 <= m.y1 and a[i].y2 <= 0) or
        (a[i].y1 >= m.y2 and a[i].y2 >= 0)) {
      cout << -1 << endl;
      return 0;
    }
    double tin_x = get_tin(a[i].x1, a[i].x2, m.x1, m.x2),
           tout_x = get_tout(a[i].x1, a[i].x2, m.x1, m.x2);
    double tin_y = get_tin(a[i].y1, a[i].y2, m.y1, m.y2),
           tout_y = get_tout(a[i].y1, a[i].y2, m.y1, m.y2);
    if (tin_x > tout_x or tin_y > tout_y) {
      cout << -1 << endl;
      return 0;
    }
    tin[i] = max(tin_x, tin_y);
    tout[i] = min(tout_x, tout_y);
  }
  double l = 0, r = MAX;
  for (int i = 0; i < n; ++i) {
    if (tin[i] >= l and tin[i] <= r) {
      l = tin[i];
      if (tout[i] >= l and tout[i] <= r) {
        r = tout[i];
      }
    } else {
      if (tout[i] >= l and tout[i] <= r) {
        r = tout[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    double nx = a[i].x1 + (l + EPS / 10) * a[i].x2;
    double ny = a[i].y1 + (l + EPS / 10) * a[i].y2;
    if (!inside(nx, ny)) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << setprecision(32) << l << endl;
}
