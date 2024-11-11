#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int a[N][N];
int getsum(int x, int y, int X, int Y) {
  return a[X][Y] + a[x - 1][y - 1] - a[X][y - 1] - a[x - 1][Y];
}
int ans[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
    }
  }
  int res = -(1e9 + 7);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int mx = min(min(i - 1, n - i), min(j - 1, m - j));
      if (mx == 0) continue;
      ans[0] = getsum(i, j, i, j);
      ans[1] = getsum(i - 1, j - 1, i - 1, j + 1) + getsum(i, j + 1, i, j + 1) +
               getsum(i + 1, j - 1, i + 1, j + 1);
      res = max(res, ans[1]);
      for (int k = 2; k <= mx; k++) {
        ans[k] = getsum(i - k, j - k, i - k, j + k) +
                 getsum(i - k + 1, j + k, i + k - 1, j + k) +
                 getsum(i + k, j - k, i + k, j + k) +
                 getsum(i - k + 2, j - k, i + k - 1, j - k) +
                 getsum(i - k + 2, j - k + 1, i - k + 2, j - k + 1) +
                 ans[k - 2];
        res = max(res, ans[k]);
      }
    }
  }
  cout << res << endl;
}
