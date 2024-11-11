#include <bits/stdc++.h>
using namespace std;
const int64_t M1 = 998244353;
const int64_t M2 = 1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int64_t n, m, k;
  cin >> n >> m >> k;
  vector<vector<int64_t>> a(n, vector<int64_t>(m));
  for (int64_t i = 0; i < n; i++)
    for (int64_t &x : a[i]) cin >> x;
  int64_t ans = n * m;
  if (m <= k) {
    for (int64_t mask = 0; mask < (1 << m); mask++) {
      int64_t sum = 0;
      for (int64_t i = 0; i < n; i++) {
        int64_t x = 0;
        for (int64_t j = 0; j < m; j++) {
          if (a[i][j] != ((mask >> j) & 1)) x++;
        }
        sum += min(x, m - x);
      }
      ans = min(ans, sum);
    }
  } else {
    for (int64_t l = 0; l < m; l++) {
      int64_t sum = 0;
      for (int64_t j = 0; j < m; j++) {
        int64_t x = 0;
        for (int64_t i = 0; i < n; i++) {
          if (a[i][l] != a[i][j]) x++;
        }
        sum += min(x, n - x);
      }
      ans = min(ans, sum);
    }
  }
  if (ans > k) ans = -1;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
