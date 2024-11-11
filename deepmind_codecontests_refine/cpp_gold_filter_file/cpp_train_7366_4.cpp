#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8, pi = 3.1415926535897932384626433832795;
int a, b, l, i;
double lo, hi, m1, m2, ans;
double calc(double x) { return cos(x) * (b * tan(x) + a - l * sin(x)); }
int main() {
  scanf("%d%d%d", &a, &b, &l);
  if (a > b) swap(a, b);
  lo = 0, hi = pi / 2;
  if (l <= b) {
    ans = min(l, a);
  } else {
    for (i = 1; i <= 300; ++i) {
      m1 = (lo + lo + hi) / 3;
      m2 = (lo + hi + hi) / 3;
      if (calc(m1) > calc(m2))
        lo = m1;
      else
        hi = m2;
    }
    ans = calc(lo);
  }
  if (ans < eps)
    puts("My poor head =(");
  else
    printf("%.8lf\n", ans);
  return 0;
}
