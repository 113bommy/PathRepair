#include <bits/stdc++.h>
using namespace std;
struct yyy {
  long long l, r;
};
yyy a[20];
yyy q[1005];
double dp[1005][1005];
long long f(long long l, long long r, int k) {
  if (a[k].r < l || a[k].l > r) return 0;
  if (a[k].l >= l && a[k].r <= r) return a[k].r - a[k].l + 1;
  if (a[k].l <= l && a[k].r >= r) return r - l + 1;
  if (a[k].r >= l && l >= a[k].l) return a[k].r - l + 1;
  if (r >= a[k].l && a[k].l >= l) return r - a[k].l + 1;
}
int main() {
  int i, j, k;
  a[1].l = a[1].r = 1;
  for (i = 2; i <= 18; i++) a[i].l = a[i - 1].l * 10, a[i].r = 2 * a[i].l - 1;
  a[i].l = a[i].r = a[i - 1].l * 10;
  int n;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> q[i].l >> q[i].r;
  cin >> k;
  k = ceil(1.0 * n * k / 100);
  dp[0][0] = 1.0;
  for (i = 1; i <= n; i++) {
    long long s = 0, m = q[i].r - q[i].l + 1;
    for (j = 1; j <= 18; j++) s += f(q[i].l, q[i].r, j);
    for (j = 0; j < i; j++)
      dp[i][j] += dp[i - 1][j] * (m - s) / m,
          dp[i][j + 1] += dp[i - 1][j] * s / m;
  }
  double ans = 0;
  for (i = k; i <= n; i++) ans += dp[n][i];
  printf("%.12f\n", ans);
  return 0;
}
