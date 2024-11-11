#include <bits/stdc++.h>
using namespace std;
long long dp[10][150];
long long b_c[150][150];
int a[15];
int n;
long long mod = 1000000007;
int main() {
  dp[10][0] = 1;
  cin >> n;
  for (int i = 0; i < 10; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    b_c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      b_c[i][j] = (b_c[i - 1][j - 1] + b_c[i - 1][j]) % mod;
  }
  for (int len = 9; len > 0; len--) {
    for (int i = 0; i <= n; i++) {
      for (int j = a[len]; j <= i; j++) {
        dp[len][i] = (dp[len][i] + dp[len + 1][i - j] * b_c[i][j]) % mod;
      }
    }
  }
  long long ans = 0;
  for (int i = a[0]; i <= n; i++) {
    for (int j = a[0]; j < i; j++) {
      ans = (ans + dp[1][i - j] * b_c[i - 1][j]) % mod;
    }
  }
  cout << ans;
  return 0;
}
