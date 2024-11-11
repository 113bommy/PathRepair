#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int dp[500];
bool solve(const string &s, const string &t) {
  for (int n = 1; n <= t.size(); n++) {
    int m = t.size() - n;
    for (int i = 0; i < 500; i++) dp[i] = -1;
    dp[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j >= 0; j--) {
        if (dp[j] == -1) continue;
        if (j + 1 <= n && s[i] == t[j]) {
          dp[j + 1] = max(dp[j + 1], dp[j]);
        }
        if (dp[j] + 1 <= m && s[i] == t[n + dp[j]]) {
          dp[j] += 1;
        }
      }
    }
    if (dp[n] == m) return true;
  }
  return false;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    cout << (solve(s, t) ? "YES\n" : "NO\n");
  }
  return 0;
}
