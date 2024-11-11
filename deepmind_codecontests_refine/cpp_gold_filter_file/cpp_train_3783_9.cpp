#include <bits/stdc++.h>
using namespace std;
static const int N = 501;
static int c[N][N];
static int s[N][N];
static int spiral[N][N];
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> c[i][j];
      s[i + 1][j + 1] = c[i][j] + s[i][j + 1] + s[i + 1][j] - s[i][j];
      spiral[i][j] = c[i][j];
    }
  int max = -INT_MAX;
  for (int k = 3; k <= min(m, n); k += 2)
    for (int i = 0; i <= m - k; ++i)
      for (int j = 0; j <= n - k; ++j) {
        spiral[i][j] = s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j] -
                       c[i + 1][j] - spiral[i + 1][j + 1];
        if (spiral[i][j] > max) max = spiral[i][j];
      }
  cout << max << endl;
  return 0;
}
