#include <bits/stdc++.h>
using namespace std;
int n, k;
double m;
double v1, v2;
bool pass(double lim) {
  int num = n;
  double now = 0.0;
  double tim = 0.0;
  for (; num;) {
    if (now + (lim - tim) * v1 >= m) return true;
    if (now + (lim - tim) * v2 < m) return false;
    num = max(num - k, 0);
    double tmp = ((lim - tim) * v1 - m + now) / (v1 - v2);
    tim += tmp;
    now += tmp * v1;
    if (tim > lim) return false;
    if (num) {
      double hit = tmp * (v2 - v1) / (v1 + v2);
      tim += hit;
      now += hit * v1;
      if (tim > lim) return false;
    }
  }
  return !num;
}
int main() {
  scanf("%d%lf%lf%lf%d", &n, &m, &v1, &v2, &k);
  double l = 0.0, r = (double)10000000000007.0;
  for (int i = 1; i <= 100; i++) {
    double mid = (l + r) / 2.0;
    if (pass(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10f", l);
}
