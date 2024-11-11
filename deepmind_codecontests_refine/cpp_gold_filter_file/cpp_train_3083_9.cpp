#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int inf = 0x3f3f3f3f;
int p[maxn][maxn], f[maxn][maxn];
long long n, m, k, q, ans = inf, a, b, t;
int main() {
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= m; k++) p[i][k] = inf;
  }
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> t;
    p[a][b] = t;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j + k <= m + 1; j++) {
      long long max1 = 0;
      for (int j1 = 0; j1 < k; j1++) {
        max1 = max(max1, (long long)p[i][j + j1]);
      }
      f[i][j] = max1;
    }
  }
  for (int i = 1; i + k <= n + 1; i++) {
    for (int j = 1; j + k <= m + 1; j++) {
      long long max1 = 0;
      for (int j1 = 0; j1 < k; j1++) {
        max1 = max(max1, (long long)f[j1 + i][j]);
      }
      ans = min(ans, max1);
    }
  }
  if (ans == inf)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
  return 0;
}
