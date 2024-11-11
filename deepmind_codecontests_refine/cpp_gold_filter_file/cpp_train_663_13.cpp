#include <bits/stdc++.h>
using namespace std;
const int N = 30;
const int lim = 2604;
string s;
vector<char> res;
int cnt[N];
int dp[lim][lim];
void trace(int i, int j) {
  if (s[i] != s[j]) {
    if (dp[i][j] == dp[i + 1][j])
      trace(i + 1, j);
    else if (dp[i][j] == dp[i][j - 1])
      trace(i, j - 1);
  } else {
    if (j - i >= 2)
      res.push_back(s[i]);
    else {
      res.push_back(s[i]);
      return;
    }
    trace(i + 1, j - 1);
  }
}
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] >= 100) {
      for (int j = 1; j <= 100; j++) {
        cout << char(i + 'a');
      }
      return 0;
    }
  }
  int n = s.length();
  s = "2" + s;
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      if (s[i] != s[j])
        dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
      else {
        if (len > 2)
          dp[i][j] = dp[i + 1][j - 1] + 2;
        else
          dp[i][j] = 2;
      }
    }
  }
  trace(1, n);
  if (res.size() <= 50) {
    for (int i = 0; i < res.size() - (dp[1][n] % 2); i++) {
      cout << res[i];
    }
    for (int i = res.size() - 1; i >= 0; i--) {
      cout << res[i];
    }
  } else {
    while (res.size() > 50) {
      res.pop_back();
    }
    for (int i = 0; i < res.size(); i++) {
      cout << res[i];
    }
    for (int i = res.size() - 1; i >= 0; i--) {
      cout << res[i];
    }
  }
}
