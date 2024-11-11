#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const long long infll = (long long)1e18;
const int LOG = 12;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (int i = 0; i < 26; ++i) cin >> cnt[i];
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = cnt[s[i] - 'a'];
  vector<vector<char>> ok(n, vector<char>(n, false));
  int maxx = 0;
  for (int i = 0; i < n; ++i) {
    int mn = inf;
    for (int j = i; j < n; ++j) {
      mn = min(mn, a[j]);
      if (mn >= (j - i + 1)) {
        ok[i][j] = true;
        maxx = max(maxx, j - i + 1);
      }
    }
  }
  vector<int> dp(n + 1, 0);
  vector<int> cc(n + 1, inf);
  dp[0] = 1;
  cc[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      if (ok[i - 1][j - 1]) {
        dp[j] += dp[i - 1];
        dp[j] %= mod;
        cc[j] = min(cc[j], cc[i - 1] + 1);
      }
    }
  }
  cout << dp[n] % mod << "\n" << maxx << "\n" << cc[n];
}
int main() {
  srand(time(NULL));
  solve();
  ;
  return 0;
}
