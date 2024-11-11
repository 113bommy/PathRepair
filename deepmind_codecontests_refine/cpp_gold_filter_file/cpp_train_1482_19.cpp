#include <bits/stdc++.h>
using namespace std;
struct seg {
  int seg[(1 << 18)];
  int k;
  void init(int n) {
    for (int i = 0; i < (1 << 18); i++) {
      seg[i] = 0;
    }
    for (k = 1; k < n; k <<= 1)
      ;
  }
  void update(int a, int x) {
    a += k;
    seg[a] = x;
    while (a > 1) {
      a >>= 1;
      seg[a] = max(seg[2 * a], seg[2 * a + 1]);
    }
  }
  int query(int l, int r) {
    l += k;
    r += k;
    int res = 0;
    while (l < r) {
      if (l % 2 == 1) res = max(res, seg[l++]);
      if (r % 2 == 0) res = max(res, seg[r--]);
      l >>= 1;
      r >>= 1;
    }
    if (l == r) res = max(res, seg[l]);
    return res;
  }
} seg[51];
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
  vector<vector<int>> r(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    seg[i].init(m);
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      s[i][j + 1] = s[i][j] + a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int val = s[i][min(m, j + k)] - s[i][j];
      r[i][j] = val;
    }
  }
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < m; i++) {
    dp[0][i] = r[0][i] + r[1][i];
    seg[0].update(i, dp[0][i]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= m - k; j++) {
      int mx = dp[i - 1][j];
      for (int p = j - k + 1; p < j + k; p++) {
        if (p < 0 or p >= m) continue;
        if (p == j) continue;
        if (p + k < j + k) {
          mx = max(mx, s[i][j + k] - s[i][p + k] + dp[i - 1][p]);
        } else {
          mx = max(mx, s[i][p] - s[i][j] + dp[i - 1][p]);
        }
      }
      dp[i][j] = max(dp[i][j], mx + r[i + 1][j]);
      if (j - k >= 0) {
        dp[i][j] =
            max(dp[i][j], r[i][j] + r[i + 1][j] + seg[i - 1].query(0, j - k));
      }
      if (j + k < m) {
        dp[i][j] =
            max(dp[i][j], r[i][j] + r[i + 1][j] + seg[i - 1].query(j + k, m));
      }
      seg[i].update(j, dp[i][j]);
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res = max(res, dp[i][j]);
    }
  }
  cout << res << endl;
}
