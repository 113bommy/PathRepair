#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  long long suma = 0;
  long long sumb = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d", &a[i], &b[i]);
    suma += a[i];
    sumb += b[i];
  }
  if (p >= suma) {
    printf("-1\n");
  } else {
    double l = 0;
    double r = 1e18;
    double mid = (l + r) / 2.0;
    while (r - l > 1e-10) {
      double e = mid * p;
      bool flag = true;
      for (int i = 0; i < n; i++) {
        if (a[i] * mid > e + b[i] * 1.0) {
          flag = false;
          break;
        } else {
          e -= (double)min(0.0, a[i] * mid - b[i] * 1.0);
        }
      }
      if (flag)
        l = mid;
      else
        r = mid;
      mid = (l + r) / 2.0;
    }
    printf("%6f\n", mid);
  }
  return 0;
}
