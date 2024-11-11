#include <bits/stdc++.h>
using namespace std;
const double exps = 1e-10;
const int INF = 0x3f3f3f3f;
int to_int(double x) { return round(x); }
int main() {
  double a, b;
  while (~scanf("%lf%lf", &a, &b)) {
    if (a < b) {
      printf("-1\n");
      continue;
    }
    double ans = INF;
    int k;
    k = to_int((a - b) / (2 * b));
    if (k > 0) ans = (a - b) / (2.0 * k);
    ans = min(ans, (a + b) / (2.0 * (k + 1)));
    printf("%.12lf\n", ans);
  }
  return 0;
}
