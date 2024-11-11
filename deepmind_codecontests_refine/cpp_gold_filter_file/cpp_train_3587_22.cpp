#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1511;
int n, m;
int a[N][N];
int64_t f[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
    for (int j = 1; j < m; ++j) a[i][j] += a[i][j - 1];
  }
  memset(f, 0xF0, sizeof(f));
  f[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int64_t p = f[i][0];
    for (int j = 1; j <= m; ++j) {
      if (p + a[i][j - 1] > f[i + 1][j]) f[i + 1][j] = p + a[i][j - 1];
      p = max(p, f[i][j]);
    }
    ++i;
    if (i == n) break;
    p = f[i][m + 1];
    for (int j = m; j >= 1; --j) {
      if (p + a[i][j - 1] > f[i + 1][j]) f[i + 1][j] = p + a[i][j - 1];
      p = max(p, f[i][j]);
    }
  }
  int64_t ans = -1e18;
  for (int j = 1; j <= m; ++j) ans = max(ans, f[n][j]);
  cout << ans << endl;
  return 0;
}
