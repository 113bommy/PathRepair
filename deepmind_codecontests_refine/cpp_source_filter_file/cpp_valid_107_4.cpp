#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long x[205], y[205];
long long area[205][205][205];
pair<long long, long long> dp[205][205];
long long n, cuts;
bool check(long long s) {
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) dp[i][j] = make_pair(0LL, 0LL);
  }
  for (long long d = 2; d < n; d++) {
    for (long long i = 1; i <= n; i++) {
      long long j = (i + d - 1) % n + 1;
      for (long long jump = 1; jump < d; jump++) {
        long long k = (i + jump - 1) % n + 1;
        long long cnt = dp[i][k].first + dp[k][j].first,
                  spare = dp[i][k].second + dp[k][j].second + area[i][j][k];
        if (spare >= s) {
          cnt++;
          spare = 0;
        }
        dp[i][j] = max(dp[i][j], make_pair(cnt, spare));
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (dp[i][(i + n - 2) % n + 1].first >= cuts + 1) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> cuts;
  for (long long i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      for (long long k = j + 1; k <= n; k++) {
        area[i][j][k] = x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - x[j] * y[i] -
                        x[k] * y[j] - x[i] * y[k];
        if (area[i][j][k] < 0) area[i][j][k] = -area[i][j][k];
        area[i][k][j] = area[j][i][k] = area[j][k][i] = area[k][i][j] =
            area[k][j][i] = area[i][j][k];
      }
    }
  }
  long long l = 1, r = 2e16;
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << "\n";
}
