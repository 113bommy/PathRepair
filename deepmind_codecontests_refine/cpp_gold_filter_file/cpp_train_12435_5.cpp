#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> str;
  vector<int> seq(str.size());
  int n = (int)str.size();
  for (int i = 0; i < seq.size(); ++i) {
    seq[i] = str[i] - '0';
  }
  vector<vector<long long> > dp(n, vector<long long>(10, 0LL));
  for (int i = 0; i < 10; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int a = 0; a < 10; ++a) {
      if (dp[i - 1][a] != 0) {
        int x = a + seq[i];
        int y = x >> 1;
        dp[i][y] += dp[i - 1][a];
        if ((y << 1) != x) {
          dp[i][y + 1] += dp[i - 1][a];
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 10; ++i) {
    ans += dp[n - 1][i];
  }
  bool valid = true;
  for (int i = 1; i < n; ++i) {
    int x = seq[i] + seq[i - 1];
    int y = x >> 1;
    if (y == seq[i]) continue;
    if (2 * y != x && (y + 1) == seq[i]) continue;
    valid = false;
    break;
  }
  if (valid) ans--;
  cout << ans << endl;
}
