#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e9 + 7;
int a[17];
int c[107][107];
int dp[17][107];
int n;
int solve(int dig, int len) {
  if (dig == 10) return len == 0;
  int &tp = dp[dig][len];
  if (tp == -1) {
    tp = 0;
    for (int tim = a[dig]; tim <= len; tim++) {
      tp +=
          (c[len - ((dig) ? 0 : 1)][tim] * 1ll * solve(dig + 1, len - tim)) % M;
      tp %= M;
    }
  }
  return tp;
}
int main() {
  cin >> n;
  for (int i = 0; i < 10; i++) cin >> a[i];
  for (int i = 0; i <= 100; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j] % M;
    }
  }
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int len = 1; len <= n; len++) {
    ans = (ans + solve(0, len)) % M;
  }
  cout << ans << '\n';
  return 0;
}
