#include <bits/stdc++.h>
using namespace std;
string s;
map<char, int> mp;
int dp[2605][2605];
void solve() {
  cin >> s;
  if (s.size() >= 2600) {
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
      if (mp[s[i]] >= 100) {
        for (int j = 1; j <= 100; j++) cout << s[j];
        return;
      }
    }
  }
  string t;
  for (int i = 0; i < s.size(); i++) t = s[i] + t;
  s = " " + s;
  t = " " + t;
  for (int i = 1; i < s.size(); i++)
    for (int j = 1; j < t.size(); j++) {
      if (s[i] == t[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  int i = s.size() - 1, j = t.size() - 1;
  string res;
  while (i > 0 && j > 0) {
    if (s[i] == t[j]) {
      res += s[i];
      i--;
      j--;
    } else {
      if (dp[i][j] == dp[i - 1][j])
        i--;
      else
        j--;
    }
  }
  if (res.size() <= 100)
    cout << res;
  else {
    if (res.size() % 2 == 0) {
      int cur = (res.size() - 100) / 2;
      int sz = res.size();
      res = " " + res;
      for (int i = cur + 1; i <= sz - cur - 1; i++) cout << res[i];
    } else {
      int pos_erase = res.size() / 2;
      res.erase(pos_erase, 1);
      int cur = (res.size() - 100) / 2;
      int sz = res.size();
      res = " " + res;
      for (int i = cur + 1; i <= sz - cur - 1; i++) cout << res[i];
    }
  }
}
int main() { solve(); }
