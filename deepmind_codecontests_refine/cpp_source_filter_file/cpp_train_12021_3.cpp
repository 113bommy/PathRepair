#include <bits/stdc++.h>
using namespace std;
int n, m;
double c[1005], dp[1005], a[1005], b[1005];
int pre[1005], ans[1005];
bool check(double x) {
  for (int i = 1; i <= n; ++i) c[i] = x * b[i];
  for (int i = 1; i <= n; ++i) {
    dp[i] = -1e60;
    for (int j = 0; j < i; ++j)
      if (dp[j] + c[i] - sqrt(fabs(a[i] - a[j] - m)) > dp[i]) {
        dp[i] = dp[j] + c[i] - sqrt(fabs(a[i] - a[j] - m));
        pre[i] = j;
      }
  }
  return dp[n] > -1e-4;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &a[i], &b[i]);
  double l = 0, r = 1000, mid;
  while (l + 1e-4 < r) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  int tot = 0;
  for (int i = n; i; i = pre[i]) ans[tot++] = i;
  printf("%d", ans[tot - 1]);
  for (int i = tot - 2; i >= 0; --i) printf(" %d", ans[i]);
  return 0;
}
