#include <bits/stdc++.h>
using namespace std;
const long long mod = static_cast<long long>(1e9 + 7);
void add(long long& a, long long b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int> > next(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[n - 1]) {
      next[i][n - 1] = 0;
    } else {
      next[i][n - 1] = -1;
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = i; j < n - 1; ++j) {
      if (s[i] != s[j]) {
        next[i][j] = 0;
      } else {
        next[i][j] = next[i + 1][j + 1];
        if (next[i][j] != -1) {
          ++next[i][j];
        }
      }
    }
  }
  vector<vector<long long> > dp(n, vector<long long>(n + 1));
  vector<vector<long long> > pref(n, vector<long long>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j > i + 1) {
        pref[i][j] = pref[i][j - 1];
        continue;
      }
      if (j == i + 1) {
        dp[i][j] = 1;
        pref[i][j] = pref[i][j - 1];
        add(pref[i][j], 1);
        continue;
      }
      if (s[i - j + 1] == '0') {
        dp[i][j] = 0;
        pref[i][j] = pref[i][j - 1];
        continue;
      }
      dp[i][j] = pref[i - j][j - 1];
      pref[i][j] = pref[i][j - 1];
      add(pref[i][j], dp[i][j]);
      if (2 * j > i + 1) {
        continue;
      }
      int x = next[i - 2 * j + 1][i - j + 1];
      if (x == -1 || x >= j) {
        continue;
      }
      if (s[i - 2 * j + 1 + x] < s[i - j + 1 + x]) {
        add(dp[i][j], dp[i - j][j]);
        add(pref[i][j], dp[i - j][j]);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp[n - 1][i];
  }
  cout << ans << "\n";
}
