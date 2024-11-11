#include <bits/stdc++.h>
using namespace std;
int dp[100002][2];
const int MOD = 1000000007;
void solve() {
  string a, b;
  int m, cnt = 0, lcnt;
  cin >> a >> b >> m;
  for (int i = 0; i < a.length(); i++) {
    if (b == a.substr(i, a.length() - i) + a.substr(0, i)) cnt++;
  }
  if (a == b)
    dp[0][0] = 1;
  else
    dp[0][1] = 1;
  lcnt = a.length() - cnt;
  for (int i = 1; i <= m; i++) {
    dp[i][0] = (dp[i - 1][0] * (cnt - 1) + dp[i - 1][1] * cnt) % MOD;
    dp[i][1] = (dp[i - 1][0] * (lcnt) + dp[i - 1][1] * (lcnt - 1)) % MOD;
  }
  cout << dp[m][0] << endl;
}
int main() {
  solve();
  return 0;
}
