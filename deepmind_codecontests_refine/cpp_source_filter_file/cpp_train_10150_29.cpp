#include <bits/stdc++.h>
const long long MAX_N = 500 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
long long dp1[MAX_N][MAX_N];
long long dp2[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) a[i][j + 1] = (s[j] - 'a') + 1;
  }
  if (a[1][1] != a[n][m]) return cout << 0, 0;
  dp1[1][n] = 1;
  for (int i = 3; i <= ceil((m + n + 1) / (long double)2); ++i) {
    vector<int> g1, g2;
    for (int j = 1; j <= min(n, i - 1); ++j) {
      if (i - j > m) continue;
      g1.push_back(j);
    }
    int x = m + n - i + 2;
    for (int j = 1; j <= min(n, x - 1); ++j) {
      if (x - j > m) continue;
      g2.push_back(j);
    }
    int t = g1.size();
    for (int j = 0; j < t; ++j) {
      int p1 = g1[j];
      for (int k = 0; k < t; ++k) {
        int p2 = g2[k];
        if (a[p1][i - p1] != a[p2][x - p2]) continue;
        dp2[p1][p2] = (dp1[p1 - 1][p2 + 1] + dp1[p1 - 1][p2] + dp1[p1][p2 + 1] +
                       dp1[p1][p2]) %
                      MOD;
      }
    }
    for (int k = 1; k <= n; ++k) {
      for (int j = 1; j <= n; ++j) {
        dp1[k][j] = dp2[k][j];
        dp2[k][j] = 0;
      }
    }
  }
  long long ans = 0;
  if ((m + n - 1) & 1) {
    for (int i = 1; i <= n; ++i) ans += dp1[i][i], ans %= MOD;
  } else {
    int t = (m + n) / 2;
    for (int i = 1; i <= min(n, t - 1); ++i) {
      if (t - i > m) continue;
      ans += dp1[i][i];
      ans += dp1[i][i + 1];
      ans %= MOD;
    }
  }
  cout << ans;
  return 0;
}
