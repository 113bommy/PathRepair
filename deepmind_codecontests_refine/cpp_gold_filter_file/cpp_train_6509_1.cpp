#include <bits/stdc++.h>
using std::cin;
using std::cout;
const long long N = 2e5 + 7, inf = 1e18;
long long a[N], s[N], q[N];
double b[N], c[N], res[N], cnt[N], f[57][N];
long long x(long long p) { return s[p]; }
double y(long long p, long long c) {
  return f[c - 1][p] + 1.0 * s[p] * res[p] - cnt[p];
}
double slope(long long a, long long b, long long c) {
  if (x(a) == x(b)) return y(a, c) > y(b, c) ? inf : -inf;
  return 1.0 * (y(a, c) - y(b, c)) / (x(a) - x(b));
}
signed main() {
  std::ios::sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    b[i] = 1.0 / a[i], res[i] = res[i - 1] + b[i];
    c[i] = 1.0 * s[i] / a[i], cnt[i] = cnt[i - 1] + c[i];
  }
  for (long long i = 1; i <= n; ++i) f[0][i] = inf;
  for (long long i = 1; i <= m; ++i) {
    long long l = 1, r = 0;
    q[++r] = 0;
    for (long long j = 1; j <= n; ++j) {
      while (l < r && slope(q[l + 1], q[l], i) <= res[j]) ++l;
      f[i][j] =
          f[i - 1][q[l]] + cnt[j] - cnt[q[l]] - s[q[l]] * (res[j] - res[q[l]]);
      while (l < r && slope(j, q[r - 1], i) <= slope(q[r], q[r - 1], i)) --r;
      q[++r] = j;
    }
  }
  cout << f[m][n] << '\n';
  return 0;
}
