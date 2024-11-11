#include <bits/stdc++.h>
using namespace std;
double a[200005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
  double x;
  double low = 0, high = 10000;
  for (int t = 1; t <= 100; t++) {
    double mid = (low + high) / 2;
    for (int i = 1; i <= n; i++) a[i] -= mid;
    double ans(0), tmp1(0), tmp2(0);
    for (int i = 1; i <= n; i++) {
      ans += a[i];
      if (ans <= 0) ans = 0;
      tmp1 = max(tmp1, ans);
      a[i] = -1.0 * a[i];
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += a[i];
      if (ans <= 0) ans = 0;
      tmp2 = max(tmp2, ans);
      a[i] = -a[i];
    }
    if (tmp1 > tmp2)
      low = mid;
    else
      high = mid;
    for (int i = 1; i <= n; i++) a[i] += mid;
  }
  double mid = (low + high) / 2;
  for (int i = 1; i <= n; i++) a[i] -= mid;
  double ans(0), tmp1(0), tmp2(0);
  for (int i = 1; i <= n; i++) {
    ans += a[i];
    if (ans <= 0) ans = 0;
    tmp1 = max(tmp1, ans);
    a[i] = -a[i];
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i];
    if (ans <= 0) ans = 0;
    tmp2 = max(tmp2, ans);
  }
  printf("%.15f", min(tmp1, tmp2));
  return 0;
}
