#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
const int maxn = 3e3 + 10;
const int maxq = 1e3 + 10;
const int alf = 26;
const int dlm = 1e9 + 7;
const long long mod = 998244353;
string O[] = {"YES", "NO", "Yes", "No"};
int lane = 2575;
int r[333];
int dp[maxn][maxn];
int mark[maxn];
string s;
void dfs(int l, int r, string& ans) {
  if (ans.size() == 100) return;
  if (l == r) {
    ans += s[l - 1];
    return;
  }
  if (l > r) return;
  if (s[l - 1] == s[r - 1] && dp[l][r] == dp[l + 1][r - 1] + 2) {
    ans += s[l - 1];
    dfs(l + 1, r - 1, ans);
    ans += s[r - 1];
    return;
  }
  if (dp[l][r - 1] == dp[l][r]) {
    dfs(l, r - 1, ans);
    return;
  }
  if (dp[l + 1][r] == dp[l][r]) {
    dfs(l + 1, r, ans);
    return;
  }
  if (dp[l + 1][r - 1] == dp[l][r]) {
    dfs(l + 1, r - 1, ans);
    return;
  }
}
int main() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i < s.size(); i++) {
    char v = s[i];
    r[v]++;
  }
  char q = '|';
  for (char i = 'a'; i <= 'z'; i++) {
    if (r[i] >= 100) {
      q = i;
      break;
    }
  }
  if (q >= 'a' && q <= 'z') {
    for (int i = 1; i <= 100; i++) {
      cout << q;
    }
    return 0;
  }
  for (int len = 0; len < n; len++) {
    for (int l = 1; (l + len) <= n; l++) {
      int r = len + l;
      if (len == 0) {
        dp[l][l] = 1;
        continue;
      }
      if (s[l - 1] == s[r - 1]) {
        dp[l][r] = dp[l + 1][r - 1] + 2;
      } else {
        dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
      }
    }
  }
  string ans = "";
  dfs(1, n, ans);
  cout << ans;
}
