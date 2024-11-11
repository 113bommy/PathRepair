#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
double s1, s2, ans[10005];
double calc(double r2, double r3) {
  double sum1 = s2 + r3;
  return 2.0 * sum1 - r2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    double r1, r2, r3;
    int k;
    scanf("%lf%lf%d", &r1, &r2, &k);
    r3 = r1 - r2;
    s2 = 1 / r2 - 1 / r1;
    ans[0] = 1.0 / r3;
    ans[1] = r3 = calc(s2 + 1 / r3, r3);
    for (int i = 2; i <= k; ++i) ans[i] = r3 = calc(ans[i - 2], r3);
    printf("%.10lf\n", 1.0 / r3);
  }
  return 0;
}
