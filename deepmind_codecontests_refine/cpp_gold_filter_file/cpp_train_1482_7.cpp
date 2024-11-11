#include <bits/stdc++.h>
using namespace std;
long long int pow_mod(long long int a, long long int b) {
  long long int res = 1;
  while (b != 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res;
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int a[n + 1][m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) cin >> a[i][j];
  }
  for (long long int j = 0; j < m; j++) a[n][j] = 0;
  long long int dp[n + 1][m];
  memset(dp, 0, sizeof(dp));
  long long int sum[n + 1][m], mx_p[n + 1][m], mx_s[n + 1][m];
  memset(sum, 0, sizeof(sum));
  memset(mx_s, 0, sizeof(mx_s));
  memset(mx_p, 0, sizeof(mx_p));
  for (long long int i = 0; i <= n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (j == 0)
        sum[i][j] = a[i][j];
      else
        sum[i][j] = a[i][j] + sum[i][j - 1];
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (j - k + 1 >= 0) {
        if (i == 0) {
          dp[i][j] = sum[i][j] - (j - k >= 0 ? sum[i][j - k] : 0LL);
        } else {
          dp[i][j] = sum[i][j] - (j - k >= 0 ? sum[i][j - k] : 0LL);
          dp[i][j] += sum[i - 1][j] - (j - k >= 0 ? sum[i - 1][j - k] : 0LL);
          if (i != 1) {
            long long int res = 0;
            if (j + k < m) res = mx_s[i - 1][j + k];
            if (j - k >= 0) res = max(res, mx_p[i - 1][j - k]);
            for (long long int xx = j; xx > max(-1LL, j - k); xx--)
              res = max(res, dp[i - 1][xx] - sum[i - 1][xx] +
                                 (j - k >= 0 ? sum[i - 1][j - k] : 0LL));
            for (long long int xx = j + 1; xx < min(m, j + k); xx++)
              res = max(res, dp[i - 1][xx] - sum[i - 1][j] +
                                 (xx - k >= 0 ? sum[i - 1][xx - k] : 0LL));
            dp[i][j] += res;
          }
        }
        mx_p[i][j] = dp[i][j];
        if (j - 1 >= 0) mx_p[i][j] = max(mx_p[i][j], mx_p[i][j - 1]);
      }
    }
    for (long long int j = m - 1; j >= 0; j--) {
      if (j == m - 1)
        mx_s[i][j] = dp[i][j];
      else
        mx_s[i][j] = max(mx_s[i][j + 1], dp[i][j]);
    }
  }
  long long int ans = 0;
  for (long long int j = 0; j < m; j++) {
    ans = max(ans, dp[n][j]);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) solve();
  return 0;
}
