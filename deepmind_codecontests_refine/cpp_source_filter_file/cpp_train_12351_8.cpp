#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n;
long long win, a, b;
long long pwin[2001];
long long plose[2001];
long long p[2001][2001];
long long pf[2001][2001];
long long dp[2001];
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  if (y % 2) return x * pw(x, y - 1) % mod;
  long long res = pw(x, y / 2);
  return res * res % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  win = a * pw(b, mod - 2);
  pwin[0] = plose[0] = 1;
  for (int i = 1; i <= n; i++) {
    pwin[i] = pwin[i - 1] * win % mod;
    plose[i] = plose[i - 1] * (mod + 1 - win) % mod;
  }
  for (int i = 1; i <= n; i++) {
    p[i][0] = p[i][i] = 1;
    for (int j = 1; j < i; j++) {
      p[i][j] = (p[i - 1][j - 1] * plose[i - j] + p[i - 1][j] * pwin[j]) % mod;
    }
  }
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    pf[i][i] = 1;
    for (int j = 1; j < i; j++) {
      pf[i][j] = p[i][j] * pf[j][j] % mod;
      dp[i] = (dp[i] + (i * (i - 1) / 2 - (i - j) * (i - j - 1) / 2 + dp[j] +
                        dp[i - j]) *
                           pf[i][j]) %
              mod;
      pf[i][i] -= pf[i][j];
      if (pf[i][i] < 0) pf[i][i] += mod;
    }
    dp[i] = (dp[i] + pf[i][i] * (i * (i - 1) / 2)) % mod;
    dp[i] = (dp[i] * pw(mod + 1 - pf[i][i], mod - 2)) % mod;
  }
  cout << dp[n] << endl;
}
