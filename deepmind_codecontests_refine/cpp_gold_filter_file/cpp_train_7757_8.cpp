#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 1;
const int MOD = 1e9 + 7;
long long dp[N][N];
void solve(int i) {
  if (i == N) return;
  if (i > 1) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = 0;
      if (j) dp[i][j] += (dp[i - 1][j - 1]) % MOD;
      if (j < N - 1) dp[i][j] += (dp[i - 1][j + 1]) % MOD;
      dp[i][j] %= MOD;
    }
  }
  solve(i + 1);
}
int main() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  dp[1][1] = 1;
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  solve(1);
  int CT = 0;
  int minCT = 100000;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '(')
      CT++;
    else
      CT--;
    minCT = min(minCT, CT);
  }
  if (abs(CT) > n - m)
    cout << "0\n";
  else {
    long long ans = 0;
    int ct = abs(CT);
    for (int i = 0; i <= n - m; ++i) {
      for (int j = 0; j < N; ++j) {
        if (minCT + j >= 0) ans += (dp[i][j] * dp[n - m - i][CT + j]) % MOD;
        ans %= MOD;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
