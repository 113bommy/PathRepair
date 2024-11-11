#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const double EPS = 0.000001;
const long long INF = 1e18;
const long long mod = 7340033;
int t, n, m, ans, cnt1, cnt2, sum[65][65];
char mp[65][65];
int calc(int a, int b, int c, int d) {
  return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}
void solve() {
  cin >> n >> m;
  cnt1 = 0;
  cnt2 = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mp[i][j];
      cnt1 += (mp[i][j] == 'A');
      if (2 <= i && i < n && 2 <= j && j < m) cnt2 += (mp[i][j] == 'A');
      sum[i][j] =
          sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (mp[i][j] == 'A');
    }
  }
  if (cnt1 == 0) {
    cout << "MORTAL\n";
    return;
  }
  if (cnt1 == m * n) {
    cout << "0\n";
    return;
  }
  ans = 4;
  if (cnt1 > cnt2) ans = 3;
  if (mp[1][1] == 'A' || mp[1][m] == 'A' || mp[n][1] == 'A' || mp[n][m] == 'A')
    ans = 2;
  if (calc(1, 1, 1, m) == m || calc(n, 1, n, m) == m || calc(1, 1, 1, n) == n ||
      calc(1, m, n, m) == n) {
    cout << "1\n";
    return;
  }
  for (int j = 2; j < m; ++j) {
    if (calc(1, j, n, j) == n) {
      cout << "2\n";
      return;
    }
  }
  for (int i = 2; i < n; ++i) {
    if (calc(i, 1, i, m) == m) {
      cout << "2\n";
      return;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
