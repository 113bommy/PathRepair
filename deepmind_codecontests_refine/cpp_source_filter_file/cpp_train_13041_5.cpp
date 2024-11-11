#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 10;
string s;
string dpstr[sz], pre[sz];
int dp[sz];
string cropPre(string s) { return s.substr(0, min((size_t)3, s.length())); }
string crop(string s) {
  if (s.length() <= 10) return s;
  string ret = "";
  ret += s.substr(0, 5);
  ret += "...";
  ret += s.substr(s.length() - 2, 2);
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int n = s.length();
  dpstr[n] = "";
  pre[n] = "";
  dp[n] = 0;
  dpstr[n - 1] = s.substr(n - 1, 1);
  pre[n - 1] = dpstr[n - 1];
  dp[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    dpstr[i] = crop(s[i] + dpstr[i + 1]);
    pre[i] = cropPre(s[i] + pre[i + 1]);
    dp[i] = dp[i + 1] + 1;
    if (s[i] == s[i + 1]) {
      if (pre[i].compare(pre[i + 2]) > 0) {
        pre[i] = pre[i + 2];
        dpstr[i] = dpstr[i + 2];
        dp[i] = dp[i + 2];
      }
    }
  }
  for (int i = 0; i < n; i++) cout << dp[i] << ' ' << dpstr[i] << '\n';
  return 0;
}
