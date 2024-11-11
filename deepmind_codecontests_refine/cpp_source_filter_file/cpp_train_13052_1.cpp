#include <bits/stdc++.h>
using namespace std;
int n, k, f[1005];
int dp[1005][1005][4], C[1005][1005], Ans[1005];
inline int Pow_Log(int x, int p) {
  int sol = 1;
  while (p) {
    if (p & 1) {
      sol = (1LL * sol * x) % 1000000007;
      --p;
    }
    p >>= 1;
    x = (1LL * x * x) % 1000000007;
  }
  return sol;
}
inline void Fix(int &x) {
  if (x >= 1000000007) x -= 1000000007;
  if (x < 0) x += 1000000007;
}
int main() {
  int i, j;
  cin.sync_with_stdio(0);
  cin >> n >> k;
  f[0] = 1;
  for (i = 1; i <= n; ++i) f[i] = (1LL * f[i - 1] * i) % 1000000007;
  for (i = 0; i <= n; ++i) C[i][0] = 1;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      Fix(C[i][j]);
    }
  dp[0][0][0] = 1;
  for (i = 1; i <= n; ++i)
    for (j = 0; j <= i; ++j) {
      dp[i][j][0] = dp[i - 1][j][0];
      dp[i][j][0] += dp[i - 1][j][2];
      Fix(dp[i][j][0]);
      if (i - 1) {
        dp[i][j][0] += dp[i - 1][j - 1][0];
        Fix(dp[i][j][0]);
      }
      if (i + 1 <= n) {
        dp[i][j][1] = dp[i - 1][j - 1][0];
        dp[i][j][1] += dp[i - 1][j - 1][2];
        Fix(dp[i][j][1]);
      }
      dp[i][j][2] = dp[i - 1][j][1];
      dp[i][j][2] += dp[i - 1][j][3];
      Fix(dp[i][j][2]);
      if (i - 1) {
        dp[i][j][2] += dp[i - 1][j - 1][1];
        Fix(dp[i][j][2]);
      }
      if (i + 1 <= n) {
        dp[i][j][3] = dp[i - 1][j - 1][1];
        dp[i][j][3] += dp[i - 1][j - 1][3];
        Fix(dp[i][j][3]);
      }
    }
  for (i = 0; i <= n; ++i)
    for (j = 0; j < 4; ++j) {
      Ans[i] += (1LL * dp[n][i][j] * f[n - i]) % 1000000007;
      Fix(Ans[i]);
    }
  for (i = n - 1; i >= 0; --i)
    for (j = i + 1; j <= n; ++j) {
      Ans[i] -= (Ans[j] * C[j][i]) % 1000000007;
      Fix(Ans[i]);
    }
  cout << Ans[k];
  return 0;
}
