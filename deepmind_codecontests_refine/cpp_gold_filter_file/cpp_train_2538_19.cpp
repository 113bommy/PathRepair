#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long n, m, k, ans = 0;
int a[15][15], bad[15][15][15];
map<int, int> mp;
void go(int row, int col, int mc) {
  if (row == n) {
    for (int c = 1; c <= mc; c++)
      for (int d = c + 1; d <= mc; d++)
        if (mp[c] != 0 && mp[d] != 0 && mp[c] == mp[d]) return;
    int free = 0, cols = k, cur = 1;
    for (int c = 1; c <= mc; c++)
      if (mp[c] == 0)
        free++;
      else
        cols--;
    while (free--) {
      cur *= cols;
      cols--;
    }
    ans += cur;
    while (ans > mod) ans -= mod;
    return;
  }
  for (int c = 1; c <= k && c <= mc + 1; c++) {
    bool flag = 0;
    if (bad[row][col][c]) continue;
    for (int x = row; x < n; x++)
      for (int y = col; y < m; y++) bad[x][y][c]++;
    if (a[row][col] != 0 && mp[c] != 0 && mp[c] != a[row][col]) {
      for (int x = row; x < n; x++)
        for (int y = col; y < m; y++) bad[x][y][c]--;
      continue;
    }
    if (mp[c] == 0) mp[c] = a[row][col], flag = 1;
    int nmc = (c > mc ? c : mc);
    if (col < m - 1)
      go(row, col + 1, nmc);
    else
      go(row + 1, 0, nmc);
    if (flag) mp[c] = 0;
    for (int x = row; x < n; x++)
      for (int y = col; y < m; y++) bad[x][y][c]--;
  }
}
int main() {
  cin >> n >> m >> k;
  if (n + m - 1 > k) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  go(0, 0, 0);
  cout << ans << endl;
  return 0;
}
