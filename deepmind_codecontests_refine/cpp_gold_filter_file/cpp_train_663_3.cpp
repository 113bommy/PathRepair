#include <bits/stdc++.h>
using namespace std;
string s;
map<char, long long> mp;
int dp[5605][5605];
void solve() {
  cin >> s;
  if (s.size() >= 3000) {
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
      if (mp[s[i]] >= 100) {
        for (int j = 1; j <= 100; j++) cout << s[i];
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
      res = s[i] + res;
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
    if (res.size() % 2 != 0) res.erase((int)(res.size() / 2), 1);
    bool flag = true;
    while (res.size() > 100) {
      if (flag) {
        flag = false;
        res.erase(0, 1);
      } else {
        flag = true;
        res.erase(res.size() - 1, 1);
      }
    }
    cout << res;
  }
}
int main() { solve(); }
