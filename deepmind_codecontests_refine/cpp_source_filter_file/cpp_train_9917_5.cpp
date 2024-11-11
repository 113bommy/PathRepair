#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3e2 + 5;
const int mod = 1e9 + 7;
int t, n, m;
int a[maxn][maxn];
int row_max[maxn * maxn], column_max[maxn * maxn];
int ans[maxn][maxn];
queue<pair<int, int> > q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  for (int i = 1; i <= n; ++i) {
    int temp_max = 0;
    for (int j = 1; j <= m; ++j) {
      temp_max = max(temp_max, a[i][j]);
    }
    row_max[temp_max] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    int temp_max = 0;
    for (int j = 1; j <= m; ++j) {
      temp_max = max(temp_max, a[j][i]);
    }
    column_max[temp_max] = 1;
  }
  int x = 0, y = 0;
  for (int i = n * m; i >= 1; --i) {
    if (row_max[i]) x++;
    if (column_max[i]) y++;
    if (row_max[i] || column_max[i]) {
      ans[x][y] = i;
      if (row_max[i]) {
        for (int c = y - 1; c >= 1; --c) q.push({x, c});
      }
      if (column_max[i]) {
        for (int r = x - 1; r >= 1; --r) q.push({r, y});
      }
    } else {
      ans[q.front().first][q.front().second] = i;
      q.pop();
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
