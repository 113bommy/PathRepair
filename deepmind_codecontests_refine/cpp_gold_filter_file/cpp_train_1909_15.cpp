#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, MOD = 1e9 + 7;
long long dp[N][N];
string t, s;
void solve() {
  cin >> s >> t;
  long long ans = 0;
  for (int i = 1; i <= (int)(s).size(); i++) {
    for (int j = 1; j <= (int)(t).size(); j++) {
      dp[i][j] = dp[i][j - 1];
      if (s[i - 1] == t[j - 1]) dp[i][j] += (dp[i - 1][j - 1] + 1) % MOD;
      dp[i][j] %= MOD;
    }
    ans = (ans + dp[i][(int)(t).size()]) % MOD;
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
