#include <bits/stdc++.h>
using namespace std;
bool mtest = 0;
int TE = 1;
int t, mx = 0, x, y;
int d[1000005];
int dp[1000005];
int n, m;
bool check(int n, int m, int x, int y) {
  if (x > n or x < 1 or y > m or y < 1) {
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cnt = abs(i - x) + abs(j - y);
      dp[cnt]++;
    }
  }
  bool f = 1;
  for (int i = 1; i <= 1e6; i++) {
    if (dp[i] != d[i]) f = 0;
    dp[i] = 0;
  }
  return f;
}
int solve() {
  cin >> t;
  int z;
  for (int i = 1; i <= t; i++) {
    cin >> z;
    d[z]++;
    mx = max(mx, z);
  }
  for (int i = 1;; i++) {
    if (d[i] != 4 * i) {
      x = i;
      break;
    }
  }
  for (int i = 1; i * i <= t; i++) {
    if (t % i == 0) {
      n = i;
      m = t / i;
      if (check(n, m, n - x + 1, mx - n + x + 1)) {
        cout << n << " " << m << endl;
        cout << n - x + 1 << " " << mx - n + x + 1;
        return 0;
      }
      if (check(m, n, m - x + 1, mx - m + x + 1)) {
        cout << m << " " << n << endl;
        cout << m - x + 1 << " " << mx - m + x + 1;
        return 0;
      }
    }
  }
  cout << -1;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  ;
  if (mtest) cin >> TE;
  while (TE--) {
    solve();
  }
  return 0;
}
