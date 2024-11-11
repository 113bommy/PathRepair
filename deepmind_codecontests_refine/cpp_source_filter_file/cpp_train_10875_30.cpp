#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, i, j, ii, jj;
  cin >> n >> m;
  int arr[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  cin >> a >> b;
  int ans = 50000, cnt;
  for (i = 0; i <= n - a; i++) {
    for (j = 0; j <= m - b; j++) {
      cnt = 0;
      for (ii = i; ii < i + a; ii++) {
        for (jj = j; jj < j + b; jj++) {
          cnt += arr[ii][jj];
        }
      }
      ans = min(ans, cnt);
    }
  }
  for (i = 0; i <= m - a; i++) {
    for (j = 0; j <= n - b; j++) {
      cnt = 0;
      for (ii = i; ii < i + b; ii++) {
        for (jj = j; jj < j + a; jj++) {
          cnt += arr[ii][jj];
        }
      }
      ans = min(ans, cnt);
    }
  }
  cout << ans << "\n";
  return 0;
}
