#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long md = 1000000007) {
  long long res = 1;
  x %= md;
  while (y > 0) {
    if (y & 1) res = (res * x) % md;
    x = (x * x) % md;
    y = y >> 1;
  }
  return res % md;
}
long long max1(long long a, long long b, long long c = -1000000000000000000LL,
               long long d = -1000000000000000000LL) {
  long long mx1 = (a > b) ? a : b, mx2 = (c > d) ? c : d;
  return ((mx1 > mx2) ? mx1 : mx2);
}
long long dp1[1001][1001];
string second[1002];
long long n, m, q;
long long query(long long x) {
  if (x == 0) return 0;
  if (x == 1) return 1;
  long long p = 1;
  while (p * 2 <= x) p *= 2;
  p /= 2;
  long long left = x - 2 * p;
  return p + (left - query(left));
}
long long solve(long long x, long long y) {
  if (x * y == 0) return 0;
  long long a = query(x / m);
  long long b = query(y / n);
  long long ans = (a * b + (x / m - a) * (y / n - b)) * dp1[n - 1][m - 1] +
                  ((x / m) * (y / n) - (a * b + (x / m - a) * (y / n - b))) *
                      (n * m - dp1[n - 1][m - 1]);
  long long xl = x % m;
  long long yl = y % n;
  if (xl > 0)
    if (query(x / m + 1) - query(x / m) == 1) {
      long long xx = query(y / n);
      long long yy = y / n - xx;
      ans += xx * (dp1[n - 1][xl - 1]) + yy * ((n * xl) - dp1[n - 1][xl - 1]);
    } else {
      long long yy = query(y / n);
      long long xx = y / n - yy;
      ans += xx * (dp1[n - 1][xl - 1]) + yy * ((n * xl) - dp1[n - 1][xl - 1]);
    }
  if (yl > 0)
    if (query(y / n + 1) - query(y / n) == 1) {
      long long xx = query(x / m);
      long long yy = x / m - xx;
      ans += xx * (dp1[yl - 1][m - 1]) + yy * ((m * yl) - dp1[yl - 1][m - 1]);
    } else {
      long long yy = query(x / m);
      long long xx = x / m - yy;
      ans += xx * (dp1[yl - 1][m - 1]) + yy * ((m * yl) - dp1[yl - 1][m - 1]);
    }
  if (xl > 0 && yl > 0)
    if ((query(y / n + 1) - query(y / n)) ^ (query(x / m + 1) - query(x / m))) {
      ans += yl * xl - dp1[yl - 1][xl - 1];
    } else {
      ans += dp1[yl - 1][xl - 1];
    }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> m >> q;
  for (long long i = 0; i < n; i++) cin >> second[i];
  for (long long i = 0; i < n; i++) {
    dp1[i][0] = (second[i][0] - '0');
    for (long long j = 1; j < m; j++)
      dp1[i][j] = (second[i][j] - '0') + dp1[i][j - 1];
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < m; j++) dp1[i][j] += dp1[i - 1][j];
  }
  while (q--) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    swap(x1, y1);
    swap(x2, y2);
    long long ans = solve(x2, y2) - solve(x1 - 1, y2) - solve(x2, y1 - 1) +
                    solve(x1 - 1, y1 - 1);
    cout << ans << '\n';
  }
}
