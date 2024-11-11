#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1E-7;
const int oo = 123456789;
int n, a, d;
double calc(double v) {
  double t = v / a;
  if (0.5 * a * t * t < d) return (d - 0.5 * a * t * t) / v + t;
  return sqrt(2.0 * d / a);
}
int main() {
  double ans = 0;
  scanf("%d%d%d", &n, &a, &d);
  int t, v;
  for (int(i) = 0; (i) < (n); ++(i)) {
    scanf("%d%d", &t, &v);
    ans = max(ans, t + calc(v));
    printf("%.10lf\n", ans);
  }
  return 0;
}
