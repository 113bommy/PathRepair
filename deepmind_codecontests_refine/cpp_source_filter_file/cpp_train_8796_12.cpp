#include <bits/stdc++.h>
using namespace std;
double m;
long long n;
double r, v;
double bbss(double ss, double ee) {
  double mid = (ss + ee) / 2;
  if (ee - ss < 1e-12) return mid * r;
  if (m > mid * r + sin(mid) * r)
    return bbss(mid, ee);
  else
    return bbss(ss, mid);
}
int main() {
  cin >> n >> r >> v;
  double per = 2 * acos(-1.0) * r;
  while (n--) {
    long long s, e;
    double ans = double(0);
    scanf("%lld %lld", &s, &e);
    e -= s;
    s = floor((double)e / per);
    ans = per * (double)s / v;
    m = (double)e - (double)s * per;
    m /= 2;
    double x = bbss(0, acos(-1.0));
    x *= 2;
    ans += (x / v);
    printf("%.10lf\n", ans);
  }
  return 0;
}
