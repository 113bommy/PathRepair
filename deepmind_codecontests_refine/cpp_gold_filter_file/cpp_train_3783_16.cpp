#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m;
int a[N][N];
int sum[N][N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
  int res = -1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int len = min(min(i - 1, n - i), min(j - 1, m - j));
      int last = a[i][j];
      for (int k = 1; k <= len; k++) {
        last = sum[i + k][j + k] - sum[i + k][j - k - 1] -
               sum[i - k - 1][j + k] + sum[i - k - 1][j - k - 1] - last -
               a[i - k + 1][j - k];
        res = max(res, last);
      }
    }
  }
  cout << res << endl;
  return 0;
}
