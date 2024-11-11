#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
const int mod = 998244353;
int inf = 1000000000;
int n, k, L;
long long dp[N][N];
long long p[N];
long long pw(long long a, int b) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) ret = (1ll * ret * a) % mod;
    a = (1ll * a * a) % mod;
    b = b >> 1;
  }
  return ret;
}
long long add(long long a, long long b) { return (a + b) % mod; }
long long sol() {
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p[i] = (p[i - 1] * i) % mod;
  }
  dp[1][1] = 1;
  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (i + j + 2 <= 2 * n)
        dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
      if (j) dp[i + 1][j - 1] = add(dp[i + 1][j - 1], (dp[i][j] * j) % mod);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = k; j <= n; ++j) {
      if (i + j > 2 * n) break;
      ans = (ans + (dp[i][j] * dp[2 * n - i][j]) % mod * p[j]) % mod;
    }
  }
  ans = (ans * pw(dp[2 * n][0], mod - 2)) % mod;
  ans = (ans * (L * pw(2 * n + 1, mod - 2)) % mod) % mod;
  return ans;
}
int main() {
  cin >> n >> k >> L;
  cout << sol() << endl;
}
