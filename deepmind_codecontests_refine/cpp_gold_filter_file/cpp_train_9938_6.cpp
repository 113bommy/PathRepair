#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long int N = 5e3 + 30, mod = 1e9 + 7, inf = 1e18;
long long int dp[N][N], sum[N];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  dp[0][a] = 1;
  for (int i = 1; i < k + 1; i++) {
    sum[0] = 0;
    for (int j = 1; j < n + 1; j++) {
      sum[j] = (sum[j - 1] + dp[i - 1][j]) % mod;
    }
    for (int j = 1; j < n + 1; j++) {
      if (j == b) {
        dp[i][j] = 0;
        continue;
      }
      if (j < b) {
        dp[i][j] = sum[(j + b) / 2 - 1 + (j + b) % 2] + mod - dp[i - 1][j];
        dp[i][j] %= mod;
        continue;
      }
      if (sum[n] > dp[i - 1][j] + sum[(b + j) / 2])
        dp[i][j] = sum[n] - dp[i - 1][j] - sum[(b + j) / 2];
      else
        dp[i][j] = sum[n] + 5 * mod - dp[i - 1][j] - sum[(b + j) / 2];
      dp[i][j] %= mod;
    }
  }
  long long int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    ans += dp[k][i];
    ans = ans % mod;
  }
  cout << ans % mod;
  return 0;
}
