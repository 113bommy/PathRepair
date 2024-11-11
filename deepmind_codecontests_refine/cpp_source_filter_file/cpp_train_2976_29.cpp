#include <bits/stdc++.h>
using namespace std;
double a[1000003];
double b[1000003];
int main() {
  long n;
  double m;
  while (~scanf("%lld%lf", &n, &m)) {
    double w1 = 0, w2 = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &a[i], &b[i]);
      w1 += a[i];
    }
    if (w1 <= m) {
      printf("-1\n");
      continue;
    }
    double l = 0, r = 1e18;
    double z = r;
    double mid;
    for (int j = 0; j < 60; j++) {
      mid = (l + r) / 2.0;
      w2 = m * mid;
      for (int i = 0; i < n; i++) {
        if (b[i] - a[i] * mid < 0) {
          w2 += (b[i] - a[i] * mid);
        }
      }
      if (w2 < 0)
        r = mid;
      else
        l = mid;
    }
    printf("%.10f\n", mid);
  }
}
