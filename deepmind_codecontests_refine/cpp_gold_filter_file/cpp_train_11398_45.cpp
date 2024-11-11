#include <bits/stdc++.h>
using namespace std;
int dp[1002][104], n, k, MOD, Solution;
int Pow[1002], sol[1002], Proc[10][1002];
inline void ComputeDP() {
  int c;
  for (int i = 1; i < 10; ++i) dp[1][i % k]++;
  for (int i = 1; i < n; ++i) {
    if (i == n - 1)
      c = 1;
    else
      c = 0;
    for (int cif = 1; cif < 10; ++cif) {
      int x = cif * Pow[i] % k;
      dp[i + 1][x]++;
      dp[i + 1][x] %= MOD;
    }
    for (int j = 1; j < k; ++j) {
      if (dp[i][j])
        for (int cif = c; cif < 10; ++cif) {
          int x = (cif * Pow[i] + j) % k;
          dp[i + 1][x] = (dp[i + 1][x] + dp[i][j]) % MOD;
        }
    }
  }
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> k >> MOD;
  if (n == 1) {
    for (int i = 1; i < 10; ++i)
      if (i % k == 0) ++Solution;
    cout << Solution % MOD << "\n";
    return 0;
  }
  Pow[0] = 1;
  for (int i = 1; i <= n; ++i) Pow[i] = Pow[i - 1] * 10 % k;
  ComputeDP();
  Pow[0] = 1;
  for (int i = 1; i <= n; ++i) Pow[i] = 1LL * Pow[i - 1] * 10LL % MOD;
  Solution = 9LL * Pow[n - 1] % MOD;
  for (int j = 1; j < k; ++j) {
    Solution -= dp[n][j];
    if (Solution < 0) Solution += MOD;
  }
  cout << Solution << "\n";
  return 0;
}
