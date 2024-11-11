#include <bits/stdc++.h>
using namespace std;
const int nax = 2e3 + 10;
bool dp[nax][nax][10], dp1[nax][nax];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  memset(dp, 0, sizeof(dp));
  memset(dp1, 0, sizeof(dp1));
  vector<string> mp(10);
  mp[0] = "1110111";
  mp[1] = "0010010";
  mp[2] = "1011101";
  mp[3] = "1011011";
  mp[4] = "0111010";
  mp[5] = "1101011";
  mp[6] = "1101111";
  mp[7] = "1010010";
  mp[8] = "1111111";
  mp[9] = "1111011";
  int n, k;
  cin >> n >> k;
  vector<string> st(n);
  for (int i = 0; i < n; i++) cin >> st[i];
  int cnt[10][n];
  for (int i = 0; i < n; i++) {
    for (int dig = 0; dig < 10; dig++) {
      cnt[dig][i] = 0;
      for (int k = 0; k < 7; k++) {
        if (st[i][k] != mp[dig][k]) {
          if (mp[dig][k] == '1')
            cnt[dig][i]++;
          else {
            cnt[dig][i] = k + 10;
            break;
          }
        }
      }
    }
  }
  dp1[n][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int dig = 0; dig < 10; dig++) {
      for (int sum = cnt[dig][i]; sum <= k; sum++) {
        if (dp1[i + 1][sum - cnt[dig][i]]) {
          dp[i][sum][dig] = 1;
          dp1[i][sum] = 1;
        }
      }
    }
  }
  string ans;
  bool f = 0;
  int have = k;
  for (int i = 0; i < n; i++) {
    for (int dig = 9; dig >= 0; dig--) {
      if (dp[i][have][dig]) {
        ans += (dig + '0');
        have -= cnt[dig][i];
        f = 1;
        break;
      }
    }
    if (!f) break;
  }
  if (ans.empty())
    cout << "-1";
  else
    cout << ans;
}
