#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const long long N = 500 + 10;
const long long MOD = 1e9 + 7;
long long n, m, k, q;
long long x[N * N], y[N * N], t[N * N], c[N][N];
bool check(long long mid) {
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= m; j++) {
      c[i][j] = 0;
    }
  }
  for (long long i = 0; i < q; i++) {
    if (t[i] <= mid) c[x[i]][y[i]] = 1;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      c[i + 1][j + 1] += c[i][j + 1] + c[i + 1][j] - c[i][j];
    }
  }
  for (long long i = k; i <= n; i++) {
    for (long long j = k; j <= m; j++) {
      if (c[i][j] - c[i - k][j] - c[i][j - k] + c[i - k][j - k] == k * k)
        return true;
    }
  }
  return false;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k >> q;
  for (long long i = 0; i < q; i++) cin >> x[i] >> y[i] >> t[i];
  long long L = -1, R = 1e9 + 10;
  while (R - L > 1) {
    long long mid = L + R >> 1;
    if (check(mid))
      R = mid;
    else
      L = mid;
  }
  if (R > 1e9) R = -1;
  cout << R << '\n';
  return 0;
}
