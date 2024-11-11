#include <bits/stdc++.h>
using namespace std;
int a[200005];
long double b[200005];
int n;
long double dp1[200005], dp2[200005];
long double check(long double val) {
  int i;
  for (i = 0; i < n; i++) b[i + 1] = a[i] - val;
  dp1[1] = b[1];
  long double ans = b[1];
  for (i = 2; i <= n; i++) {
    dp1[i] = max(dp1[i - 1], (long double)0) + b[i];
    ans = max(ans, dp1[i]);
  }
  for (i = 0; i <= n + 1; i++) b[i + 1] = -b[i + 1];
  ans = max(ans, b[1]);
  dp2[1] = b[1];
  for (i = 2; i <= n; i++) {
    dp2[i] = max(dp2[i - 1], (long double)0) + b[i];
    ans = max(ans, dp2[i]);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  long double lo, hi;
  lo = -(1e4);
  hi = 1e4;
  long double eps = 1e-10;
  while (lo < hi - eps) {
    long double mid1, mid2;
    mid1 = (2 * lo + hi) / 3;
    mid2 = (lo + hi * 2) / 3;
    long double sol1, sol2;
    sol1 = check(mid1);
    sol2 = check(mid2);
    if (sol1 < sol2 - eps) {
      hi = mid2;
    } else {
      lo = mid1;
    }
  }
  cout << fixed << setprecision(9) << check(lo) << endl;
}
