#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
int a, b, c, d;
double ans, g[2];
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  g[1] = 1.1 * a / b, g[1] = 1.0 * (d - c) / d;
  double tmp = 1;
  while (tmp > eps) {
    ans += tmp * g[1];
    tmp *= (1 - g[1]) * g[1];
  }
  printf("%.12lf\n", ans);
  return 0;
}
