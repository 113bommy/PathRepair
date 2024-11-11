#include <bits/stdc++.h>
using namespace std;
long long dp[1050][120][2], len[1050], mod;
int n, k;
void add(long long &x, long long y) { x = (x + y) % mod; }
int main() {
  cin >> n >> k >> mod;
  dp[0][0][0] = 1, len[0] = 1;
  for (int i = 1; i < 1050; ++i) len[i] = len[i - 1] * 10 % mod;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int v = 0; v < 10; ++v) {
        if (i == n - 1 && !v) continue;
        long long val = (v * len[i] + j) % k;
        if (!val && v)
          add(dp[i + 1][0][1], dp[i][j][0]);
        else
          add(dp[i + 1][val][0], dp[i][j][0]);
        add(dp[i + 1][val][1], dp[i][j][1]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < k; ++i) ans = (ans + dp[n][i][1]) % mod;
  cout << ans << endl;
  return 0;
}
