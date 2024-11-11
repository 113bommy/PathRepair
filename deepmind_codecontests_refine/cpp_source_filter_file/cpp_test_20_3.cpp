#include <bits/stdc++.h>
using namespace std;
const long long N = 500 + 5, mod = 998244353;
char a[N][N];
long long sum[N][N];
long long f[N];
long long s(long long lx, long long ly, long long rx, long long ry) {
  return sum[rx][ry] - sum[lx - 1][ry] - sum[rx][ly - 1] + sum[lx - 1][ly - 1];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long ans = 999999999;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                     (a[i][j] == '1');
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 4; j <= n; j++) {
        for (long long k = 4; k <= m; k++) {
          f[k] = s(i + 1, 1, j - 1, k - 1) - s(i, 1, i, k - 1) -
                 s(j, 1, j, k - 1) + (k - 1) * 2 +
                 (j - i - 1 - s(i + 1, k, j - 1, k));
        }
        for (long long k = m - 1; k >= 4; k--) {
          f[k] = min(f[k + 1], f[k]);
        }
        for (long long k = 1; k <= m - 3; k++) {
          long long sh = k - s(i, 1, i, k), xi = k - s(j, 1, j, k);
          ans = min(ans, f[k + 3] + (j - i - 1 - s(i + 1, k, j - 1, k)) - sh -
                             xi - s(i + 1, 1, j - 1, k));
        }
      }
    }
    cout << ans << endl;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) sum[i][j] = 0;
    }
  }
  return 0;
}
