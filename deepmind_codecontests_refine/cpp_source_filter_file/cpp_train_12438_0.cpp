#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
inline bool lt(double a, double b) { return a + eps < b; }
inline bool eq(double a, double b) { return !lt(a, b) && !lt(b, a); }
inline bool lteq(double a, double b) { return lt(a, b) || eq(a, b); }
inline bool gteq(double a, double b) { return lt(b, a) || eq(a, b); }
int x[200002], n;
double pos1, pos2, pos3;
int prvog(double p, double d) {
  int lo = 0, hi = n - 1, mid = 0, ret = 0;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (lteq(x[mid], p + d)) {
      lo = mid + 1;
      ret = mid;
    } else
      hi = mid - 1;
  }
  return ret + 1;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  sort(x, x + n);
  double lo = 0, hi = 1000000000, d = 0;
  for (int it = 0; it < 1000; ++it) {
    d = (lo + hi) / 2;
    int i = 0;
    double pos = x[0] + d;
    pos1 = pos2 = pos3 = pos;
    i = prvog(pos, d);
    if (i < n) {
      double pos = x[i] + d;
      pos2 = pos3 = pos;
      i = prvog(pos, d);
    }
    if (i < n) {
      double pos = x[i] + d;
      pos3 = pos;
      i = prvog(pos, d);
    }
    if (i < n)
      lo = d;
    else
      hi = d;
  }
  printf("%lf\n", d);
  printf("%.6lf %.6lf %.6lf\n", pos1, pos2, pos3);
  return 0;
}
