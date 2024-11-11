#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 2e9;
constexpr int mod = 1e9 + 7;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < (n); i++) cin >> s[i];
  if (n == 1 || m == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (n > 3 && m > 3) {
    cout << -1 << endl;
    return 0;
  }
  int f = 0;
  if (n > m) swap(n, m), f = 1;
  vector<vector<int>> a(n, vector<int>(m, 0));
  if (!f)
    for (int i = 0; i < (n); i++)
      for (int j = 0; j < (m); j++) a[i][j] = s[i][j] - '0';
  else
    for (int i = 0; i < (n); i++)
      for (int j = 0; j < (m); j++) a[i][j] = s[j][n - i - 1] - '0';
  vector<int> dp(1 << n, 0);
  vector<vector<int>> ok(1 << n, vector<int>(1 << n, 1));
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      vector<int> cnt(n, 0);
      for (int k = 0; k < n; k++) {
        if (i & (1 << k)) cnt[k]++;
        if (j & (1 << k)) cnt[k]++;
      }
      for (int k = 0; k < n - 1; k++) {
        if ((cnt[k] + cnt[k + 1]) % 2 == 0) ok[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (a[0][j] ^ ((i & (1 << j)) >> j)) dp[i]++;
    }
  }
  for (int i = 1; i < m; i++) {
    vector<int> ndp(1 << n, INF);
    for (int j = 0; j < (1 << n); j++) {
      int add = 0;
      for (int k = 0; k < n; k++) {
        if (a[k][i] ^ ((j & (1 << k)) >> k)) add++;
      }
      for (int k = 0; k < (1 << n); k++) {
        if (!ok[k][j]) continue;
        ndp[j] = min(ndp[j], dp[k] + add);
      }
    }
    dp = move(ndp);
  }
  int res = INF;
  for (int i = 0; i < (1 << n); i++) res = min(res, dp[i]);
  cout << res << endl;
  return 0;
}
