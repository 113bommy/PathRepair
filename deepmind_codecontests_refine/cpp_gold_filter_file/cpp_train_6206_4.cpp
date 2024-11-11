#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  vector<vector<int>> e(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> e[i][j];
    }
  }
  int m = n / 2;
  vector<pair<int, int>> dp(1 << m);
  {
    dp[0] = {0, 0};
    for (int i = 1; i < (1 << m); ++i) {
      int size = 0;
      for (int x = 0; x < m; ++x) {
        if (1 & (i >> x)) {
          ++size;
          for (int y = x + 1; y < m; ++y) {
            if (1 & (i >> y)) {
              dp[i].first += e[x][y];
            }
          }
        }
      }
      dp[i].second = size;
      if (dp[i].first != size * (size - 1) / 2) {
        dp[i].first = -1;
      }
      for (int x = 0; x < m; ++x) {
        if (1 & (i >> x)) {
          dp[i] = max(dp[i], dp[i - (1 << x)]);
        }
      }
    }
  }
  int ans = dp[(1 << m) - 1].second;
  {
    int num = n - m;
    bitset<20> bit;
    for (int i = (1 << num) - 1; i >= 0; --i) {
      int size = 0;
      int tmp = 0;
      bit = (1 << m) - 1;
      for (int x = 0; x < num; ++x) {
        if (1 & (i >> x)) {
          size++;
          for (int y = x + 1; y < num; ++y) {
            if (1 & (i >> y)) {
              tmp += e[x + m][y + m];
            }
          }
          for (int y = 0; y < m; ++y) {
            bit[y] = bit[y] & e[x + m][y];
          }
        }
      }
      if (tmp == size * (size - 1) / 2) {
        ans = max(ans, dp[bit.to_ulong()].second + size);
      }
    }
  }
  cout << fixed << setprecision(12) << 1LL * k * k * (ans - 1) / 2.0 / ans
       << "\n";
  return 0;
}
