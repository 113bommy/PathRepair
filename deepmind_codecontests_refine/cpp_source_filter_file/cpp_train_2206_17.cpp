#include <bits/stdc++.h>
using namespace std;
int dp[100][100][100];
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  map<int, int> m;
  for (auto &i : s) m[i - 'a']++;
  for (auto &i : t) m[i - 'a']--;
  vector<vector<int> > v(26);
  for (auto &i : m)
    if (i.second != 0) {
      cout << -1 << '\n';
      return;
    }
  for (int i = 0; i < n; i++) v[s[i] - 'a'].push_back(i);
  memset(dp, 0, sizeof(dp));
  int ma = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        for (int k = 0; k < v[t[i] - 'a'].back() + 1; k++) dp[k][i][j] = 1;
        continue;
      }
      int v = 0;
      for (int k = n - 1; k >= 0; k--) {
        if (v == 1) {
          dp[k][i][j] = v;
          continue;
        }
        if (t[i] == s[k] && k < n && dp[k + 1][i + 1][j] == 1) v = 1;
        dp[k][i][j] = v;
      }
      if (v == 1) ma = max(ma, j - i + 1);
    }
  }
  cout << n - ma << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double t1 = clock();
  int t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  cerr << setprecision(10) << (clock() - t1) / CLOCKS_PER_SEC << "\n";
  return 0;
}
