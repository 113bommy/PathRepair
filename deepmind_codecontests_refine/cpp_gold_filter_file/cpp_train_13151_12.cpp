#include <bits/stdc++.h>
using namespace std;
double t, a, v, d, tm;
int n;
int main() {
  scanf("%d%lf%lf", &n, &a, &d);
  tm = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &t, &v);
    if (v * v <= 2 * a * d) {
      double tmp;
      tmp = t + v / a + (d - v * v / (2 * a)) / v;
      tm = max(tm, tmp);
    } else {
      double tmp;
      tmp = t + sqrt(2 * d / a);
      tm = max(tm, tmp);
    }
    printf("%.10lf\n", tm);
  }
  return 0;
}
