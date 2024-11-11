#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, l, r, ans1 = LONG_LONG_MAX, m, q, n, a, c;
  cin >> n;
  long long A[n], dp[n][n];
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    dp[0][i] = A[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n - i; j++) {
      dp[i][j] = dp[i - 1][j + 1] ^ dp[i - 1][j];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j + 1]));
    }
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    l = l - 1;
    cout << dp[r - l - 1][l] << '\n';
  }
  return 0;
}
