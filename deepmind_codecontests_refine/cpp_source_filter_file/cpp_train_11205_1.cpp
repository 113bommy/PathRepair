#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, s, an, sum;
class arr {
 public:
  double x, y;
} a[4];
double r[4];
const double eps = 1e-9;
double t1, t2;
double sqr(double x) { return x * x; }
double dis(arr a, arr b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
void change(arr &o, double p) {
  arr u;
  u.x = o.x * cos(p) - o.y * sin(p);
  u.y = o.x * sin(p) + o.y * cos(p);
  o = u;
}
bool pan(int A, int B, int C) {
  int k, kk;
  if (r[A] > r[B])
    k = A, kk = B;
  else
    k = B, kk = A;
  if ((dis(a[A], a[B]) + r[kk] < r[k] - eps)) {
    if (dis(a[kk], a[C]) + r[kk] < r[C] - eps) return true;
    return false;
  }
  if ((r[A] + r[B] < dis(a[A], a[B]) - eps)) return false;
  double COS = (sqr(dis(a[A], a[B])) + sqr(r[A]) - sqr(r[B])) /
               (2 * r[A] * dis(a[A], a[B]));
  if (COS > 1) COS = 1;
  if (COS < -1) COS = -1;
  double erfa = acos(COS);
  arr t, o;
  t.x = a[A].x + (a[B].x - a[A].x) * (r[A] / dis(a[A], a[B]));
  t.y = a[A].y + (a[B].y - a[A].y) * (r[A] / dis(a[A], a[B]));
  o = t;
  o.x -= a[A].x;
  o.y -= a[A].y;
  change(o, erfa);
  o.x += a[A].x;
  o.y += a[A].y;
  if (dis(o, a[C]) <= r[C] + eps) return true;
  o = t;
  o.x -= a[A].x;
  o.y -= a[A].y;
  change(o, -erfa);
  o.x += a[A].x;
  o.y += a[A].y;
  if (dis(o, a[C]) <= r[C] + eps) return true;
  return false;
}
bool cheak(double mid) {
  r[1] = mid;
  r[2] = t1 + dis(a[1], a[2]) - mid;
  r[3] = t2 + dis(a[1], a[3]) - mid;
  if (r[2] < 0) return false;
  if (r[3] < 0) return false;
  if (pan(1, 2, 3)) return true;
  if (pan(1, 3, 2)) return true;
  if (pan(2, 3, 1)) return true;
  if (pan(2, 1, 3)) return true;
  if (pan(3, 1, 2)) return true;
  if (pan(3, 2, 1)) return true;
  return false;
}
int main() {
  scanf("%lf%lf", &t2, &t1);
  for (int i = 1; i <= 3; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
  if (dis(a[1], a[3]) + dis(a[3], a[2]) <= dis(a[1], a[2]) + t1) {
    printf("%.6lf\n", dis(a[1], a[3]) + dis(a[2], a[3]) +
                          min(t2, dis(a[1], a[2]) + t1 - dis(a[2], a[3]) -
                                      dis(a[1], a[3])));
    return 0;
  }
  double l = 0;
  double r = 999999999;
  while (l < r - eps) {
    double mid = (l + r) / 2;
    if (cheak(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.6lf\n", l);
  return 0;
}
