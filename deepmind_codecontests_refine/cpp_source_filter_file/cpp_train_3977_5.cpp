#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool smin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool smax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const long long N = 100 + 10, inf = 2e18;
long long n, m, c[N][N], k, ed = 1, res[N][N], b[N << 1], dp[N << 1][N << 1];
pair<long long, long long> ar[N * N];
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
  return c[x.first][x.second] < c[y.first][y.second];
}
long long calc() {
  memset(b, 0, sizeof b);
  memset(dp, 0, sizeof dp);
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j)
      if (!b[i + j]) b[i + j] = res[i][j];
  dp[1][0] = 1;
  for (long long cur = 2; cur <= n + m; ++cur) {
    for (long long sum = 0; sum <= cur; ++sum) {
      if (b[cur] == 1) {
        if (sum) dp[cur][sum] += dp[cur - 1][sum - 1];
      } else if (b[cur] == -1) {
        dp[cur][sum] += dp[cur - 1][sum + 1];
      } else {
        if (sum) dp[cur][sum] += dp[cur - 1][sum - 1];
        dp[cur][sum] += dp[cur - 1][sum + 1];
      }
      smin(dp[cur][sum], inf);
    }
  }
  return dp[n + m][0];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j) cin >> c[i][j];
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j) ar[ed++] = make_pair(i, j);
  sort(ar + 1, ar + ed, cmp);
  for (long long cur = 1; cur < ed; ++cur) {
    long long bx = ar[cur].first, by = ar[cur].second;
    long long val = 0;
    for (long long x = 1; x <= n; ++x) {
      long long y = bx + by - x;
      if (!val) val = res[x][y];
    }
    if (!val) {
      res[bx][by] = 1;
      long long cnt = calc();
      if (cnt < k) {
        k -= cnt;
        res[bx][by] = -1;
      }
    } else
      res[bx][by] = val;
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      if (res[i][j] == -1)
        cout << ')';
      else
        cout << '(';
    }
    cout << endl;
  }
}
