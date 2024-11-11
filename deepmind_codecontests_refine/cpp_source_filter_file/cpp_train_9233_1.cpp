#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111;
const double EPS = 1e-8;
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
};
point next_point() {
  double x, y;
  scanf("%lf %lf", &x, &y);
  return point(x, y);
}
double sqr(double x) { return x * x; }
double dis(point a, point b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
int n, vb, vs, xu, yu;
double stop[MAXN];
point u;
inline double calc(double x) { return x / vb + dis(u, point(x, 0)) / vs; }
inline bool cmp(double x1, double x2) {
  return dis(u, point(x1, 0)) > dis(u, point(x2, 0));
}
int main() {
  scanf("%d %d %d", &n, &vb, &vs);
  for (int i = 0; i < n; ++i) scanf("%lf", stop + i);
  u = next_point();
  int pos = 1;
  double ans = calc(stop[1]);
  for (int i = 2; i < n; ++i) {
    double tmp = calc(stop[i]);
    if (ans > tmp || fabs(ans - tmp) < EPS && cmp(stop[pos], stop[i])) {
      ans = tmp;
      pos = i;
    }
  }
  printf("%d\n", pos);
}
