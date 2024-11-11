#include <bits/stdc++.h>
using namespace std;
const int N = 101000;
const double eps = 1e-5, g = 9.8;
double V, angle, ca, sa, Y, K, x, y;
int i, j, k, l, m, n, o, p;
inline int sn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
inline double Sqr(double x) { return x * x; }
struct Point {
  double x, y;
  inline void read() { scanf("%lf%lf", &x, &y); }
  bool operator<(const Point &t) const { return x < t.x; }
} wall[N], ans[N];
struct fire {
  double a, b;
  int i;
  fire() {}
  fire(double x, double y, int id) {
    a = x;
    b = y;
    i = id;
  }
  inline void read(int id) {
    scanf("%lf", &angle);
    ca = cos(angle);
    sa = sin(angle);
    a = g / (2 * Sqr(V * ca));
    b = sa / ca;
    i = id;
    ans[i].x = (b / a);
    ans[i].y = 0;
  }
  bool operator<(const fire &t) const {
    double b1 = b - K * a, b2 = t.b - K * t.a;
    return (b1 < b2) || (!sn(b1 - b2) && (i < t.i));
  }
} Tfire, P;
set<fire> F;
set<fire>::iterator pos;
int main() {
  scanf("%d%lf", &n, &V);
  K = (double)0.455555;
  for (i = 1; i <= n; i++) {
    Tfire.read(i);
    F.insert(Tfire);
  }
  scanf("%d", &m);
  for (i = 1; i <= m; i++) wall[i].read();
  sort(wall + 1, wall + n + 1);
  for (i = 1; i <= m; i++) {
    K = wall[i].x;
    Y = wall[i].y / wall[i].x;
    while (1) {
      pos = F.lower_bound(fire(0, Y + eps, N));
      if (pos == F.begin()) break;
      pos--;
      P = (*pos);
      j = P.i;
      if (ans[j].x > wall[i].x) {
        ans[j].x = wall[i].x;
        ans[j].y = (-P.a) * Sqr(wall[i].x) + wall[i].x * P.b;
      }
      F.erase(pos);
    }
  }
  for (i = 1; i <= n; i++) printf("%.9lf %.9lf\n", ans[i].x, ans[i].y);
  return 0;
}
