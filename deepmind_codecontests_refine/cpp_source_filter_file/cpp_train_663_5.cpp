#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2600 + 10;
int a[MAXN];
int dp[MAXN][MAXN];
pair<int, int> par[MAXN][MAXN];
int main() {
  int n;
  string s;
  string ss = "";
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) a[s[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    if (a[i] >= 100) {
      for (int j = 0; j < 100; j++) cout << (char)(i + 'a');
      cout << endl;
      return 0;
    }
  for (int i = 0; i < n; i++) dp[i][i + 1] = 1;
  for (int i = n - 1; i >= 0; i--)
    for (int j = i + 1; j <= n; j++) {
      if (s[i] == s[j - 1] and dp[i][j] < dp[i + 1][j - 1] + 2) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
        par[i][j] = make_pair(1, 1);
      }
      if (dp[i][j] < dp[i + 1][j]) {
        dp[i][j] = dp[i + 1][j];
        par[i][j] = make_pair(1, 0);
      }
      if (dp[i][j] < dp[i][j - 1]) {
        dp[i][j] = dp[i][j - 1];
        par[i][j] = make_pair(0, 1);
      }
    }
  int l = 0, r = n, len = 0;
  while (l + 1 < r) {
    if (len == 100) break;
    pair<int, int> p = par[l][r];
    if (p == make_pair(1, 1)) {
      ss += s[l];
      len += 2;
    }
    l += p.first;
    r -= p.second;
  }
  cout << ss;
  if (l + 1 == r && len != 100) cout << s[l];
  reverse(ss.begin(), ss.end());
  cout << ss << endl;
  return 0;
}
