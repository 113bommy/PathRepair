#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, d, p;
  int n;
  scanf("%lf%lf%d", &a, &d, &n);
  for (int i = 1; i <= n; ++i) {
    p = i * d;
    if (p > 4 * a) p -= 4 * a * (int)(p / (a * 4));
    if (p >= 0 && p < a) printf("%.16lf 0.0000000000\n", p);
    if (p >= a && p < 2 * a) printf("%.16lf %.16lf\n", a, p - a);
    if (p >= 2 * a && p < 3 * a) printf("%.16lf %.16lf\n", 3 * a - p, a);
    if (p >= 3 * a && p <= 4 * a) printf("0.0000000000 %.16lf\n", 4 * a - p);
  }
  return 0;
}
