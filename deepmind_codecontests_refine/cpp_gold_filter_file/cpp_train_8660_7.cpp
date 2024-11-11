#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const long long MOD = (int)1e9 + 7;
int R, C, rock[MAXN][MAXN], rsum[MAXN][MAXN], csum[MAXN][MAXN];
long long dp[2][MAXN][MAXN], sum[2][MAXN][MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      char ch;
      cin >> ch;
      rock[i][j] = (ch == '.' ? 0 : 1);
      rsum[i][j] = rsum[i][j - 1] + rock[i][j];
      csum[i][j] = csum[i - 1][j] + rock[i][j];
    }
  }
  dp[0][R][C] = dp[1][R][C] = sum[0][R][C] = sum[1][R][C] = 1;
  for (int i = R; i >= 1; i--) {
    for (int j = C; j >= 1; j--) {
      if (i == R && j == C) {
        continue;
      }
      int tot = rsum[i][C] - rsum[i][j];
      int rmost = C - tot;
      dp[0][i][j] = (sum[1][i][j + 1] - sum[1][i][rmost + 1] + MOD) % MOD;
      sum[0][i][j] = (sum[0][i + 1][j] + dp[0][i][j]) % MOD;
      tot = csum[R][j] - csum[i][j];
      rmost = R - tot;
      dp[1][i][j] = (sum[0][i + 1][j] - sum[0][rmost + 1][j] + MOD) % MOD;
      sum[1][i][j] = (sum[1][i][j + 1] + dp[1][i][j]) % MOD;
    }
  }
  if (R == 1 && C == 1) {
    cout << 1 << '\n';
  } else if (R == 1) {
    cout << dp[0][1][1] << '\n';
  } else if (C == 1) {
    cout << dp[1][1][1] << '\n';
  } else {
    cout << (dp[0][1][1] + dp[1][1][1]) % MOD << '\n';
  }
}
