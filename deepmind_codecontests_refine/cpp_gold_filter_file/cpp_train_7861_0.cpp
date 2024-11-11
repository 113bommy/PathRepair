#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1), ep = 1e-8;
int a, n;
int x[100005], y[100005];
pair<double, int> sto[100005 << 1];
int st[100005 << 1];
int chk[100005], CHK;
inline double sqr(double x) { return x * x; }
double can(double d) {
  int cnt = 0, top = 0;
  for (int i = 0; i < n; i++) {
    double d1 = sqrt(sqr(x[i] - a) + sqr(y[i]));
    double d2 = sqrt(sqr(x[i] + a) + sqr(y[i]));
    double ang = (sqr(d) + sqr(d1) - sqr(d2)) / 2 / d / d1;
    if (ang > 1 - ep || ang < -1 + ep) continue;
    ang = acos(ang);
    double mid = atan2(y[i], x[i] - a);
    double lo = mid - ang, hi = mid + ang;
    if (lo < -PI) lo += 2 * PI;
    if (hi > PI) hi -= 2 * PI;
    sto[cnt++] = make_pair(lo, i);
    sto[cnt++] = make_pair(hi, i);
  }
  CHK++;
  sort(sto, sto + cnt);
  for (int i = 0; i < cnt; i++) {
    int ps = sto[i].second;
    if (chk[ps] < CHK)
      chk[ps] = CHK, st[top++] = ps;
    else {
      if (st[top - 1] != ps) return 1;
      top--;
    }
  }
  return 0;
}
int main() {
  scanf("%d %d", &n, &a);
  for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
  double lo = 0, hi = 2 * a;
  for (int runs = 0; runs < 50; runs++) {
    double mid = (lo + hi) / 2;
    if (can(mid))
      hi = mid;
    else
      lo = mid;
  }
  printf("%.15lf\n", hi);
}
