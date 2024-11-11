#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
long long dp[2][maxn];
const long long inf = (long long)1e18;
void solve() {
  int n, x;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[i] = b[i] = x - i;
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int cnt = b.size();
  dp[0][0] = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= cnt; j++) {
      dp[0][j] += abs(a[i - 1] - b[j - 1]);
      dp[0][j] = min(dp[0][j - 1], dp[0][j]);
    }
  }
  cout << dp[0][n] << endl;
  return;
  for (int i = 0; i < cnt; i++) {
    if (i == 0)
      dp[0][i] = abs(a[0] - b[i]);
    else
      dp[0][i] = min(dp[0][i - 1], abs(0ll + a[0] - b[i]));
  }
  for (int i = 1; i < n; i++) {
    long long minn = inf;
    for (int j = 0; j < cnt; j++) {
      dp[i & 1][j] = dp[(i - 1) & 1][j] + abs(a[i] - b[j]);
      if (j) {
        minn = min(minn, dp[(i - 1) & 1][j]);
        dp[i & 1][j] = minn + abs(b[j] - a[i]);
      }
    }
  }
  long long res = inf;
  for (int i = 0; i < cnt; i++) {
    res = min(res, dp[(n - 1) & 1][i]);
  }
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}
