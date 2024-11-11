#include <bits/stdc++.h>
using namespace std;
struct Point {
  long double x, y;
} per, qwe, goal, central;
long double v, vp, r, R, ang;
long double Dist(Point p1, Point p2) {
  return (long double)sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                           (p1.y - p2.y) * (p1.y - p2.y));
}
long double slove(long double t) {
  long double angle = (ang + t * vp / R);
  goal.x = R * cos(angle), goal.y = R * sin(angle);
  long double qiexian1 = sqrt(qwe.x * qwe.x + qwe.y * qwe.y - r * r);
  long double qiexian2 = sqrt(goal.x * goal.x + goal.y * goal.y - r * r);
  long double dist = Dist(qwe, goal);
  if (dist < qiexian2 + qiexian1) {
    return dist;
  } else {
    long double dist1 = Dist(qwe, central);
    long double dist2 = Dist(goal, central);
    long double centralangle =
        acos((dist1 * dist1 + dist2 * dist2 - dist * dist) /
             (2 * dist1 * dist2)) -
        atan(qiexian1 / r) - atan(qiexian2 / r);
    return centralangle * r + qiexian1 + qiexian2;
  }
}
int main() {
  central.x = central.y = 0;
  while (scanf("%lf%lf%lf%lf%lf%lf%lf", &per.x, &per.y, &vp, &qwe.x, &qwe.y, &v,
               &r) != EOF) {
    ang = atan2(per.y, per.x);
    R = sqrt(per.x * per.x + per.y * per.y);
    long double high = 1000000, low = 0, mid;
    while (high - low > 1e-10) {
      mid = (low + high) / 2;
      if (slove(mid) <= 1e-10 + mid * v)
        high = mid;
      else
        low = mid;
    }
    printf("%.10f\n", mid);
  }
  return 0;
}
