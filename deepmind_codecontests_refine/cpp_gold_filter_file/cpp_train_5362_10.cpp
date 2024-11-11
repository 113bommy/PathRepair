#include <bits/stdc++.h>
using namespace std;
int sx, sy, tx, ty;
int v, t;
int vx, vy;
int wx, wy;
double Distance(double sx, double sy, double tx, double ty) {
  return sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));
}
double Calculate(double sx, double sy, double tx, double ty, double x, double y,
                 double l, double r, double t) {
  double o;
  while (l + 1e-7 < r) {
    o = (l + r) / 2;
    if (Distance(sx + x * o, sy + y * o, tx, ty) / v <= t + o)
      r = o;
    else
      l = o;
  }
  return l;
}
int main() {
  scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
  scanf("%d%d", &v, &t);
  scanf("%d%d", &vx, &vy);
  scanf("%d%d", &wx, &wy);
  if (Distance(sx + vx * t, sy + vy * t, tx, ty) / v <= t)
    printf("%lf\n", Calculate(sx, sy, tx, ty, vx, vy, 0, t, 0));
  else
    printf("%lf\n",
           t + Calculate(sx + vx * t, sy + vy * t, tx, ty, wx, wy, 0, 1e9, t));
  return 0;
}
