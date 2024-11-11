#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int N = 100005;
long long int cnt[30];
long long int dp[3000][3000];
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  for (long long int i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a']++;
    if (cnt[s[i] - 'a'] == 100) {
      for (long long int j = 0; j < 100; j++) cout << s[i];
      return 0;
    }
  }
  for (long long int i = 0; i < 2600; i++)
    for (long long int j = 0; j < 2600; j++)
      if (i + j < 2600) dp[j][j + i] = 1;
  for (long long int i = 1; i < s.size(); i++) {
    for (long long int j = 0; j < s.size(); j++) {
      if (j + i < s.size()) {
        if (s[j] == s[i + j]) {
          dp[j][i + j] = dp[j + 1][j + i - 1] + 2;
        } else
          dp[j][j + i] = max(dp[j + 1][j + i], dp[j][j + i - 1]);
      }
    }
  }
  string t;
  long long int i = 0, j = s.size() - 1;
  while (1) {
    if (dp[i][j] == 1) {
      t.push_back(s[j]);
      break;
    }
    if (dp[i][j] == 0) {
      break;
    }
    if (dp[i][j - 1] == dp[i][j])
      j--;
    else if (dp[i + 1][j] == dp[i][j])
      i++;
    else if (dp[i + 1][j - 1] == dp[i][j] - 2) {
      t.push_back(s[j]);
      j--;
      i++;
    }
  }
  if (t.size() <= 50) {
    string z = t;
    if (dp[0][s.size() - 1] % 2) z.pop_back();
    reverse(z.begin(), z.end());
    t += z;
    return cout << t, 0;
  } else {
    while (t.size() != 50) t.pop_back();
    string z = t;
    reverse(z.begin(), z.end());
    t += z;
    return cout << t, 0;
  }
}
