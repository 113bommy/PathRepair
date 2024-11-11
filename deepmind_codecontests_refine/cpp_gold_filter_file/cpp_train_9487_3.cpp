#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long inv[100];
long long pow(long long a, long long n) {
  if (n == 0) return 1;
  long long p = pow(a, n / 2);
  p = (p * p) % MOD;
  return (n % 2 == 0 ? p : (a * p) % MOD);
}
long long dp[100][2];
long long sol(long long p, int l, int K) {
  dp[0][0] = 1;
  for (int i = 1; i <= l; i++) dp[i][0] = (dp[i - 1][0] * p) % MOD;
  for (int k = 1; k <= K; k++) {
    dp[0][k % 2] = 1;
    for (int i = 1; i <= l; i++)
      dp[i][k % 2] = (dp[i - 1][k % 2] + dp[i][(k + 1) % 2]) % MOD;
    for (int i = 1; i <= l; i++)
      dp[i][k % 2] = (dp[i][k % 2] * inv[i + 1]) % MOD;
  }
  return dp[l][K % 2];
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 1; i <= 100; i++) inv[i] = pow(i, MOD - 2);
  long long n;
  int k;
  cin >> n >> k;
  long long ans = 1;
  for (long long d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      int l = 0;
      while (n % d == 0) {
        l++;
        n /= d;
      }
      ans = (ans * sol(d, l, k)) % MOD;
    }
  }
  if (n > 1) ans = (ans * sol(n, 1, k)) % MOD;
  cout << ans << endl;
  return 0;
}
