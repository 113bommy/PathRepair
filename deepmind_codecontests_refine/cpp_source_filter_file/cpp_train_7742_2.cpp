#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int i, j, k, l, n, m, K[120], tmp, flag, bo;
struct point {
  int x, y;
} a[120];
struct ppp {
  double x, y;
} O;
double ans;
int dot(point &a, point &b, point &c, point &d) {
  return (b.x - a.x) * (d.x - c.x) + (b.y - a.y) * (d.y - c.y);
}
double dist(ppp &a, point &b) {
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
void calc(double a, double b, double c, double d, double e, double f) {
  O.y = (a * f - d * c) / (b * d - e * a);
  O.x = (b * f - c * e) / (a * e - b * d);
}
bool Find(int x, int y) {
  for (int i = 1; i <= n; ++i)
    if (a[i].x == x && a[i].y == y) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
  for (i = 1; i <= n; ++i) K[i] = a[i].x * a[i].x + a[i].y * a[i].y;
  for (i = 1; i <= n; ++i)
    for (j = i + 1; j <= n; ++j)
      for (k = j + 1; k <= n; ++k) {
        tmp = dot(a[i], a[j], a[i], a[k]);
        bo = 0;
        if (tmp < 0 || tmp == 0 && !Find(a[j].x + a[k].x - a[i].x,
                                         a[j].y + a[k].y - a[i].y))
          continue;
        if (tmp == 0)
          bo = 1, O.x = (a[j].x + a[k].x) / 2.0, O.y = (a[j].y + a[k].y) / 2.0;
        tmp = dot(a[j], a[i], a[j], a[k]);
        if (tmp < 0 || tmp == 0 && !Find(a[i].x + a[k].x - a[j].x,
                                         a[i].y + a[k].y - a[j].y))
          continue;
        if (tmp == 0)
          bo = 1, O.x = (a[i].x + a[k].x) / 2.0, O.y = (a[i].y + a[k].y) / 2.0;
        tmp = dot(a[k], a[i], a[k], a[j]);
        if (tmp < 0 || tmp == 0 && !Find(a[i].x + a[j].x - a[k].x,
                                         a[i].y + a[j].y - a[k].y))
          continue;
        if (tmp == 0)
          bo = 1, O.x = (a[i].x + a[j].x) / 2.0, O.y = (a[i].y + a[j].y) / 2.0;
        if (!bo)
          calc(a[j].x - a[i].x, a[j].y - a[i].y, (K[i] - K[j]) / 2.0,
               a[k].x - a[i].x, a[k].y - a[i].y, (K[i] - K[k]) / 2.0);
        double R = dist(O, a[i]);
        for (l = 1; l <= n; ++l)
          if (l != i && l != j && l != k && dist(O, a[l]) + eps < R) break;
        if (l <= n) continue;
        ans = max(ans, R);
        flag = 1;
      }
  if (!flag)
    printf("-1\n");
  else
    printf("%.6lf\n", ans - 9);
}
