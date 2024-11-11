#include <bits/stdc++.h>
long long f[100];
int n;
long long m, ans;
int a[100], sa;
long long dp[100][2];
void pre() {
  f[1] = 1;
  f[2] = 2;
  for (n = 3;; n++) {
    f[n] = f[n - 1] + f[n - 2];
    if (f[n] > 1000000000000000000LL) break;
  }
}
void get_a() {
  int i;
  sa = 0;
  for (i = n; i >= 1; i--) {
    if (m >= f[i]) {
      sa++;
      a[sa] = i;
      m -= f[i];
    }
  }
}
void solve() {
  int i;
  long long s1, s2;
  get_a();
  a[sa + 1] = 0;
  dp[sa + 1][0] = 1;
  dp[sa + 1][1] = 0;
  for (i = sa; i >= 1; i--) {
    s1 = s2 = 0;
    dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
    if (dp[i + 1][0] > 0) s1 = (a[i] - a[i + 1] - 1) / 2;
    if (dp[i + 1][1] > 0) s2 = (a[i] - a[i + 1]) / 2;
    dp[i][1] = dp[i + 1][0] * s1 + dp[i + 1][1] * s2;
  }
  ans = dp[1][1] + dp[1][0];
}
int main() {
  int ca;
  int i, j;
  pre();
  scanf("%d", &ca);
  while (ca--) {
    scanf("%I64d", &m);
    ans = 0;
    solve();
    printf("%I64d\n", ans);
  }
  return 0;
}
