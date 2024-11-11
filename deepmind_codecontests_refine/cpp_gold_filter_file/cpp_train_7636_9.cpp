#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
struct Point {
  double x, y;
};
Point a, b, c;
double cross(Point a, Point b, Point c) {
  b.x -= a.x, b.y -= a.y;
  c.x -= a.x, c.y -= a.y;
  return b.x * c.y - b.y * c.x;
}
bool check(Point a, Point b, Point c) {
  double kx1 = 2.0 * (b.x - a.x), ky1 = 2.0 * (b.y - a.y),
         s1 = b.x * b.x + b.y * b.y - a.x * a.x - a.y * a.y;
  double kx2 = 2.0 * (c.x - b.x), ky2 = 2.0 * (c.y - b.y),
         s2 = b.x * b.x + b.y * b.y - c.x * c.x - c.y * c.y +
              4.0 * b.x * (c.x - b.x) + 4.0 * b.y * (c.y - b.y);
  double kx = kx1 * ky2 - kx2 * ky1, s = s1 * ky2 - s2 * ky1;
  if (kx > -eps && kx < eps) return false;
  double x = s / kx, y;
  if (ky1 <= -eps || ky1 >= eps)
    y = (s1 - kx1 * x) / ky1;
  else if (ky2 <= -eps || ky2 >= eps)
    y = (s2 - kx2 * x) / ky2;
  else
    return false;
  Point pa, pb, pc, pd;
  pa.x = x, pa.y = y;
  pb.x = b.x * 2 - x, pb.y = b.y * 2 - y;
  pc.x = c.x * 2 - pb.x, pc.y = c.y * 2 - pb.y;
  pd.x = a.x * 2 - x, pd.y = a.y * 2 - y;
  double ca = cross(pa, pb, pc), cb = cross(pb, pc, pd), cc = cross(pc, pd, pa),
         cd = cross(pd, pa, pb);
  if ((ca > 0 && cb > 0 && cc > 0 && cd > 0) ||
      (ca < 0 && cb < 0 && cc < 0 && cd < 0)) {
    printf("YES\n%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n", pa.x, pa.y,
           pb.x, pb.y, pc.x, pc.y, pd.x, pd.y);
    return true;
  }
  return false;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    if (!check(a, b, c) && !check(b, c, a) && !check(c, a, b)) printf("NO\n\n");
  }
  return 0;
}
