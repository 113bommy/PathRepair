#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long len;
    cin >> len;
    string str1, str2;
    cin >> str1 >> str2;
    vector<long long> cnt1(30, 0), cnt2(30, 0);
    for (int i = 0; i < len; i++) {
      cnt1[str1[i] - 'a']++;
      cnt2[str2[i] - 'a']++;
    }
    long long flag = 0;
    for (int i = 0; i < len; i++) {
      if (cnt1[i] != cnt2[i]) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << -1 << endl;
      continue;
    }
    long long dp[len + 1][len + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= len; j++) {
        if (str2[i - 1] == str1[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= len; i++) {
      ans = max(ans, dp[i][len]);
    }
    if (ans == 0) {
      cout << -1 << endl;
    } else {
      cout << len - ans << endl;
    }
  }
  return 0;
}
