#include <bits/stdc++.h>
using namespace std;
int a[200005];
long double b[200005];
int n;
long double solve() {
  long double ans = 0;
  long double sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    sum1 = max(b[i], sum1 + b[i]);
    ans = max(ans, sum1);
    b[i] = -b[i];
    sum2 = max(b[i], sum2 + b[i]);
    ans = max(ans, sum2);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  long double lo = 0, hi = 1e9, ans = 1e9;
  for (int i = 0; i < 200; i++) {
    long double mid1 = lo + (hi - lo) / 3;
    long double mid2 = hi - (hi - lo) / 3;
    long double res1 = -1e18, res2 = -1e18;
    for (int i = 1; i <= n; i++) {
      b[i] = a[i] - mid1;
    }
    res1 = solve();
    for (int i = 1; i <= n; i++) {
      b[i] = a[i] - mid2;
    }
    res2 = solve();
    if (res1 <= res2) {
      ans = min(ans, res1);
      hi = mid2;
    } else {
      ans = min(ans, res2);
      lo = mid1;
    }
  }
  printf("%.20Lf\n", ans);
}
