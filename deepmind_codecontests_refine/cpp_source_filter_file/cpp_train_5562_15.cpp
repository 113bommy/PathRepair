#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int MN = 33, MOD = 1e9 + 7;
long long dp[MN][MN], pw[MN * MN], dp1[MN][MN];
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int k;
  cin >> k;
  for (int i = 0; i < MN; ++i) dp[i][0] = 1;
  dp[0][1] = 1;
  pw[0] = 1;
  for (int i = 1; i < MN * MN; ++i) pw[i] = pw[i - 1] * 2 % MOD;
  for (int i = 1; i < MN; ++i)
    for (int j = 1; j < MN; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (i - j + 1 >= 0)
        dp[i][j] = (dp[i][j] + pw[i - j + 1] * dp[i - 1][j - 1]) % MOD;
    }
  int c = 0;
  for (int i = 30; ~i; --i) {
    if (k & (1 << i)) ++c;
    for (int j = 0; j < MN; ++j) {
      if (!j) {
        if (!c) dp1[i][j] = 1;
        continue;
      }
      if (k & (1 << i))
        dp1[i][j] = (dp1[i + 1][j] * pw[j - 1] + dp1[i + 1][j - 1]) % MOD;
      else
        dp1[i][j] = (dp1[i + 1][j] * pw[j - 1]) % MOD;
    }
  }
  long long ans = 0;
  for (int i = 30; ~i; --i)
    if (k & (1 << i)) {
      long long sv = ans;
      for (int sz1 = 0; sz1 <= 31; ++sz1)
        for (int sz2 = 0; sz2 <= i; ++sz2)
          (ans += dp1[i + 1][sz1] * (sz1 ? pw[sz1 - 1] : 1) *
                  (i ? dp[i - 1][sz2] : 1) % MOD * pw[sz1 * (i - sz2)] % MOD) %=
              MOD;
    }
  for (int sz1 = 0; sz1 <= 31; ++sz1) ans = (ans + dp1[0][sz1]) % MOD;
  cout << ans << endl;
  return 0;
}
