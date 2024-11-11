#include <bits/stdc++.h>
using namespace std;
template <typename T>
T hungarian(const vector<vector<T>>& cost) {
  const T INF = numeric_limits<T>::max();
  long long n = cost.size(), m = cost[0].size();
  vector<T> u(n + 1), v(m + 1), dist(m + 1);
  vector<long long> p(m + 1), way(m + 1), used(m + 1);
  for (long long i = 1; i <= n; ++i) {
    p[0] = i;
    long long j0 = 0;
    fill(dist.begin(), dist.end(), INF);
    do {
      used[j0] = i;
      long long i0 = p[j0], j1 = -1;
      T delta = INF;
      for (long long j = 1; j <= m; ++j)
        if (used[j] != i) {
          T cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
          if (cur < dist[j]) dist[j] = cur, way[j] = j0;
          if (dist[j] < delta) delta = dist[j], j1 = j;
        }
      for (long long j = 0; j <= m; j++) {
        if (used[j] == i)
          u[p[j]] += delta, v[j] -= delta;
        else
          dist[j] -= delta;
      }
      j0 = j1;
    } while (p[j0] != 0);
    for (long long j1; j0; j0 = j1) p[j0] = p[j1 = way[j0]];
  }
  return -v[0];
}
long long dp[1 << 22];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    dp[arr[i]] = arr[i];
  }
  for (long long mask = 0; mask < 22; mask++) {
    for (long long i = 0; i < (1 << 22); i++) {
      if (~dp[i]) {
        dp[i | 1 << mask] = dp[i];
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << dp[~arr[i] & ((1 << 22) - 1)] << " ";
  }
}
