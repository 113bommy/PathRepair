#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> a;
vector<vector<int>> val;
int32_t main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  val.resize(n + 5, vector<int>(m + 5, 1e5));
  a.resize(n + 5, vector<char>(m + 5, '#'));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  long long ans = 0;
  for (int x = 0; x < 26; ++x) {
    for (int i = 0; i < (int)val.size(); ++i) {
      for (int j = 0; j < (int)val[0].size(); ++j) {
        val[i][j] = 1e5;
      }
    }
    for (int i = 1; i <= n; ++i) {
      int len = 1, r = 1;
      for (int j = 1; j <= m; ++j) {
        if (a[i][j] != 'a' + x) continue;
        r = max(r, j);
        len = min(len, r - j + 1);
        while (j - len > 0 && j + len <= m && a[i][j - len] == 'a' + x &&
               a[i][j + len] == 'a' + x)
          ++len;
        r = max(r, j + len - 1);
        val[i][j] = min({i, j, n - i + 1, m - j + 1, val[i][j], 2 * len - 1});
      }
    }
    for (int j = 1; j <= m; ++j) {
      int len = 1, r = 1;
      for (int i = 1; i <= n; ++i) {
        if (a[i][j] != 'a' + x) continue;
        r = max(r, i);
        len = min(len, r - i + 1);
        while (i - len > 0 && i + len <= n && a[i - len][j] == 'a' + x &&
               a[i + len][j] == 'a' + x)
          ++len;
        r = max(r, i + len - 1);
        val[i][j] = min(val[i][j], 2 * len - 1);
        val[i][j] = min({val[i][j], val[i - 1][j] + 1, val[i][j - 1] + 1});
      }
    }
    for (int i = n; i > 0; --i) {
      for (int j = m; j > 0; --j) {
        val[i][j] = min({val[i][j], val[i + 1][j] + 1, val[i][j + 1] + 1});
        if (a[i][j] == 'a' + x) ans += val[i][j];
      }
    }
  }
  cout << ans << '\n';
}
