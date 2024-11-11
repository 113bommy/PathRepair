#include <bits/stdc++.h>
using namespace std;
const string NAME = "vd";
const int MOD = 1e9 + 7;
int td[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, tc[8] = {0, 1, 0, -1, -1, 1, 1, -1};
long long n, ans[5005], dp[30][5005];
string s;
signed main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> s;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    int idx = s[i] - 'a' + 1;
    long long tmp = 1;
    for (int j = 1; j <= n; ++j) {
      ans[j] = (ans[j] - dp[idx][j] + MOD) % MOD;
      dp[idx][j] = tmp % MOD;
      tmp = (tmp + ans[j]) % MOD;
      ans[j] = (ans[j] + dp[idx][j]) % MOD;
    }
  }
  cout << ans[n] << '\n';
  return 0;
}
