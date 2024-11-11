#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-7;
int n, k;
double v1, v2, s, cur, t;
inline bool Check(double x, int n, double s) {
  while (s > 0 && x > 0) {
    if (n <= k) {
      x -= s / v2;
      break;
    }
    if (x * v1 >= s) return 1;
    double tmp = (x - s / v1) / ((v1 - v2) / v1), S = s - tmp * v2;
    x -= tmp;
    n -= k;
    s -= tmp * v1;
    tmp = (s - S) / (v1 + v2);
    x -= tmp;
    s -= tmp * v1;
  }
  if (x < 0) return 0;
  return 1;
}
int main() {
  scanf("%d%lf%lf%lf%d", &n, &s, &v1, &v2, &k);
  double l = 0, r = s / v1;
  while (r - l > 3e-7) {
    double Mid = (l + r) / 2;
    if (Check(Mid, n, s))
      r = Mid;
    else
      l = Mid;
  }
  printf("%.7lf\n", l);
  return 0;
}
