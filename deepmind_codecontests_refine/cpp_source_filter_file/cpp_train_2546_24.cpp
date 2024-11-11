#include <bits/stdc++.h>
using namespace std;
const double g = 9.8;
int n, m;
double V, a[100008], f[100008];
struct arr {
  double x, y;
  bool operator<(const arr &t) const { return x < t.x; }
} b[100008];
struct Tprogram {
  void open() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
  }
  void close() {}
  double down(double a) { return V * V * sin(a) * cos(a) * 2 / g; }
  double get(double m, double x) {
    double t = tan(m);
    return t * x - g * x * x * (1 + t * t) / (2 * V * V);
  }
  double jie(double x, double y) {
    double l = 0, r = 3.1415926535897 / 4;
    for (int i = 1; i <= 100; i++) {
      double m = (l + r) / 2;
      if (get(m, x) >= y)
        r = m;
      else
        l = m;
    }
    return r;
  }
  void init() {
    scanf("%d%lf", &n, &V);
    for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf("%lf%lf", &b[i].x, &b[i].y);
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; i++) {
      f[i] = jie(b[i].x, b[i].y);
      f[i] = (f[i] > f[i - 1] ? f[i] : f[i - 1]);
    }
  }
  void work() {
    b[m + 1].x = 1e9;
    for (int i = 1; i <= n; i++) {
      int l = 1, r = m;
      while (l <= r) {
        int mid = l + r >> 1;
        if (a[i] > f[mid] + 1e-6)
          l = mid + 1;
        else
          r = mid - 1;
      }
      if (down(a[i]) < b[l].x)
        printf("%lf %lf\n", down(a[i]), 0.0);
      else
        printf("%lf %lf\n", b[l].x, get(a[i], b[l].x));
    }
  }
} Program;
int main() {
  Program.init();
  Program.work();
  return 0;
}
