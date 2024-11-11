#include <bits/stdc++.h>
using namespace std;
const int N = 4010, mod = 998244353;
int ksm(long long a, int b, int c = 1) {
  for (; b; b /= 2, a = a * a % mod)
    if (b & 1) c = c * a % mod;
  return c;
}
int n, K, L, dp[N][N], ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> K >> L;
  dp[0][0] = 1;
  for (int i = 1; i <= 2 * n; ++i)
    for (int j = 0; j <= n; ++j)
      if (dp[i - 1][j]) {
        dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
        if (j)
          dp[i][j - 1] = (dp[i][j - 1] + (long long)dp[i - 1][j] * j) % mod;
      }
  for (int i = 1; i <= 2 * n; ++i)
    for (int j = 1, k = 1; j <= n; ++j, k = (long long)k * j % mod)
      if (j >= K)
        ans = (ans + (long long)dp[i][j] * dp[n * 2 - i][j] % mod * k) % mod;
  cout << ksm((long long)(2 * n + 1) * dp[2 * n][0] % mod, mod - 2,
              (long long)ans * L % mod)
       << '\n';
  return 0;
}
