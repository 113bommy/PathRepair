#include <bits/stdc++.h>
using namespace std;
const long long lmt = 1e5 + 5;
bool pixel[520][520];
long long n, m, k, q, sum[520][520];
pair<long long, pair<long long, long long>> broke[lmt];
bool ok(long long yet) {
  for (long long i = 1; i <= yet; i++) {
    long long x = broke[i].second.first, y = broke[i].second.second;
    pixel[x][y] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      sum[i][j] += (pixel[i][j]);
    }
  }
  bool yes = 0;
  for (long long i = 1; i <= n; i++) {
    bool don = 0;
    for (long long j = 1; j <= m; j++) {
      if (i - k + 1 > 0 && j - k + 1 > 0) {
        long long now =
            sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
        if (now == (k * k)) {
          don = 1;
          yes = 1;
          break;
        }
      }
    }
    if (don) break;
  }
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= m; j++) {
      sum[i][j] = pixel[i][j] = 0;
    }
  }
  return yes;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k >> q;
  for (long long i = 1; i <= q; i++) {
    long long x, y, t;
    cin >> x >> y >> t;
    broke[i].first = t, broke[i].second.first = x, broke[i].second.second = y;
  }
  sort(broke + 1, broke + q + 1);
  long long lo = 1, hi = q;
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (ok(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  if (ok(lo))
    cout << broke[lo].first << "\n";
  else if (ok(hi))
    cout << broke[hi].first << "\n";
  else
    cout << -1 << "\n";
  return 0;
}
