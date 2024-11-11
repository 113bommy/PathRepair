#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 1005;
long long dp[N][N][3], sdp[N][N][3];
long long arr[N], ncr[N][N];
void func(int n) {
  memset(dp, 0, sizeof(dp));
  memset(sdp, 0, sizeof(sdp));
  dp[0][0][2] = sdp[0][0][2] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0][2] = 1;
    sdp[i][0][2] = 1;
    for (int k = 1; k <= n; k++) {
      dp[i][k][2] = (dp[i - 1][k][0] + dp[i - 1][k][1] + dp[i - 1][k][2]) % mod;
      if (i + 1 <= n) {
        dp[i][k][1] =
            (dp[i - 1][k - 1][0] + dp[i - 1][k - 1][1] + dp[i - 1][k - 1][2]) %
            mod;
      }
      if (i >= 2 && k >= 2) {
        dp[i][k][0] += dp[i - 2][k - 2][0];
        if (dp[i][k][0] >= mod) dp[i][k][0] -= mod;
        dp[i][k][0] += dp[i - 2][k - 2][2];
        if (dp[i][k][0] >= mod) dp[i][k][0] -= mod;
      }
      if (i >= 2 && k >= 1) {
        dp[i][k][0] += sdp[i - 2][k - 1][0];
        if (dp[i][k][0] >= mod) dp[i][k][0] -= mod;
        dp[i][k][0] += sdp[i - 2][k - 1][2];
        if (dp[i][k][0] >= mod) dp[i][k][0] -= mod;
      }
      sdp[i][k][2] = sdp[i - 1][k - 1][2] + dp[i][k][2];
      if (sdp[i][k][2] >= mod) sdp[i][k][2] -= mod;
      sdp[i][k][0] = sdp[i - 1][k - 1][0] + dp[i][k][0];
      if (sdp[i][k][0] >= mod) sdp[i][k][0] -= mod;
    }
  }
  memset(ncr, 0, sizeof(ncr));
  ncr[0][0] = 1;
  for (int i = 1; i < N; i++) {
    ncr[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
      if (ncr[i][j] >= mod) ncr[i][j] -= mod;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  int n, k;
  cin >> n >> k;
  func(n);
  for (int i = 1; i <= n; i++) {
    arr[i] = (dp[n][i][0] + dp[n][i][1] + dp[n][i][2]) % mod;
    for (int j = 1; j <= n - i; j++) {
      (arr[i] *= j) %= mod;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      arr[i] += mod - (arr[j] * ncr[j][i] % mod);
    }
    arr[i] %= mod;
  }
  cout << arr[k] << endl;
  return 0;
}
