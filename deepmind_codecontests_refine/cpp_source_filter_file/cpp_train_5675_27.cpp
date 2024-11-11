#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
struct Vector {
  double x, y;
  Vector(double x = 0, double y = 0) : x(x), y(y) {}
};
void inv(Vector &x) { scanf("%lf%lf", &x.x, &x.y); }
Vector addv(Vector x, Vector y) { return Vector(x.x + y.x, x.y + y.y); }
void out(Vector x) { cout << x.x << ' ' << x.y << ' '; }
int solve(Vector v0, Vector vt, double vm, double t, double dt = 0) {
  Vector tmp = addv(v0, Vector(vt.x * t, vt.y * t));
  t += dt;
  double ans = tmp.x * tmp.x + tmp.y * tmp.y - vm * t * vm * t;
  if (ans > 1e-7)
    return -1;
  else if (ans < -1e-7)
    return 1;
  else
    return 0;
}
int main() {
  Vector p0, p1, v;
  double vm, t;
  inv(p0), inv(p1);
  p0.x *= -1, p0.y *= -1;
  v = addv(p0, p1);
  scanf("%lf%lf", &vm, &t);
  inv(p0), inv(p1);
  p0.x *= -1, p0.y *= -1;
  p1.x *= -1, p1.y *= -1;
  if (solve(v, p0, vm, t) >= 0) {
    double l = 0, r = t;
    for (int i = 0; i < 100; i++) {
      double m = (l + r) / 2;
      if (solve(v, p0, vm, m) > 0)
        r = m;
      else if (solve(v, p0, vm, m) < 0)
        l = m;
      else {
        l = m;
        break;
      }
    }
    printf("%.7lf\n", l);
  } else {
    v = addv(v, Vector(p0.x * t, p0.y * t));
    double l = 0, r = 1000000007;
    for (int i = 0; i < 100; i++) {
      double m = (l + r) / 2;
      if (solve(v, p1, vm, m, t) > 0)
        r = m;
      else if (solve(v, p1, vm, m, t) < 0)
        l = m;
      else {
        l = m;
        break;
      }
    }
    printf("%.7lf\n", l + t);
  }
  return 0;
}
