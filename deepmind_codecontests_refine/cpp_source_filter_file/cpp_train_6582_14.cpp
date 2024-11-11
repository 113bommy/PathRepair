#include <bits/stdc++.h>
using namespace std;
struct combina {
  vector<vector<long long>> dp;
  combina(int n) {
    dp.resize(n + 1, vector<long long>(n + 1));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= i; k++) {
        dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1];
      }
    }
  }
  int operator()(int n, int k) { return dp[n][k]; }
};
void solve() {
  long long n, m, t;
  cin >> n >> m >> t;
  long long ans = 0;
  combina cba(40);
  for (int i = 4; i <= n; i++) {
    if (1 <= t - i && t - i <= m) {
      ans += cba(n, i) * cba(m, t - i);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
