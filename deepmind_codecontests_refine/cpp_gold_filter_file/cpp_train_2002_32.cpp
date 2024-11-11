#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 1e6, INFi = 1e9 + 123, MOD = 1e9 + 7, KEY = 1001;
const long long INFl = 1e18 + 123;
const double EPS = 0.000000001;
template <typename T>
inline T sqr(T t) {
  return t * t;
}
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
char a[N][N];
long long n, m, k, dp[N][N], ans;
inline int get(int l, int r, int u, int d) {
  if (r - l < 2 || d - u < 2) return 0;
  return dp[d - 1][r - 1] - dp[d - 1][l] - dp[u][r - 1] + dp[u][l];
}
inline void check(int l, int r) {
  int d = 3;
  for (int u = 1; u < n - 1; u++) {
    while (get(l, r, u, d) < k && d < n) d++;
    if (get(l, r, u, d) >= k) ans += n - d + 1;
  }
}
int main() {
  file();
  cin >> n >> m >> k;
  if (n < 3 || m < 3) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i > 1 && i < n && j > 1 && j < m && a[i - 1][j] == '1' &&
          a[i + 1][j] == '1' && a[i][j - 1] == '1' && a[i][j + 1] == '1' &&
          a[i][j] == '1')
        dp[i][j]++;
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  for (int i = 1; i < m - 1; i++)
    for (int j = i + 2; j <= m; j++) check(i, j);
  cout << ans;
}
