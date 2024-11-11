#include <bits/stdc++.h>
using namespace std;
const long long N = 3000;
const long long mod = 998244353;
long long dp[N][N], fp[N + 1][N + 1];
int main() {
  vector<long long> exp;
  exp.push_back(1);
  for (long long i = 1; i <= N; i++) {
    exp.push_back((exp[i - 1] * 2) % mod);
  }
  string second;
  cin >> second;
  string T;
  cin >> T;
  long long m = T.length();
  for (long long i = 0; i < m; i++) {
    dp[i][i] = (second[0] == T[i] ? 2 : 0);
  }
  for (long long dif = 1; dif < m; dif++) {
    for (long long i = 0; i < m - dif; i++) {
      long long j = i + dif;
      dp[i][j] = 0;
      if (second[dif] == T[i]) {
        dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
      }
      if (second[dif] == T[j]) {
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
      }
    }
  }
  long long n = second.length();
  fp[1][0] = 2;
  fp[1][1] = (second[0] == T[m - 1] ? 2 : 0);
  for (long long len = 2; len <= n; len++) {
    fp[len][0] = exp[len];
    for (long long k = 1; k <= min(len, m); k++) {
      if (k == len) {
        fp[len][k] = dp[m - k][m - 1];
        continue;
      }
      fp[len][k] = fp[len - 1][k];
      if (second[len - 1] == T[m - k]) {
        fp[len][k] = (fp[len][k] + fp[len - 1][k - 1]) % mod;
      }
    }
  }
  long long ans = 0;
  for (long long len = m; len <= n; len++) {
    ans = (ans + fp[len][m]) % mod;
  }
  cout << ans << '\n';
  return 0;
}
