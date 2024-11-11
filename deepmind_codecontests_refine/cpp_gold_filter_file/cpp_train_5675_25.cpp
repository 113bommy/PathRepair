#include <bits/stdc++.h>
using namespace std;
double xx1, yy1, xx2, yy2, vm, t, vx, vy, wx, wy;
inline double Distance(double x, double y) { return sqrt(x * x + y * y); }
inline double Zero(double x) {
  if (fabs(x) < 1e-10) return 0;
  if (x < 0) return -1;
  return 1;
}
inline bool Check(double tt) {
  double x = xx1 + min(tt, t) * vx + max(tt - t, 0.0) * wx;
  double y = yy1 + min(tt, t) * vy + max(tt - t, 0.0) * wy;
  double tmp = Distance(xx2 - x, yy2 - y), tmp2 = tt * vm;
  if (Zero(tmp - tmp2) <= 0) return 1;
  return 0;
}
inline void Mybin(double low, double high) {
  for (double mid = (low + high) * 0.5; high - low > 1e-10;
       (Check(mid) ? high = mid : low = mid), mid = (low + high) * 0.5)
    ;
  printf("%.18lf\n", low);
}
inline void solve() {
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &xx1, &yy1, &xx2, &yy2, &vm, &t, &vx,
        &vy, &wx, &wy);
  Mybin(0.0, 100000000.0);
}
int main() {
  solve();
  return 0;
}
