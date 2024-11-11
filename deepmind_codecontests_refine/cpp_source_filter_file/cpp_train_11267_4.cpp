#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << '\n';
}
const long long N = 1e5 + 10, oo = 1e18 + 500;
const long long mod = 1e9 + 7;
const long double eps = 1e-9, PI = 2 * acos(0.0);
long long n, m, k;
long long cnt = 0;
vector<long long> g[N];
vector<long long> rg[N];
vector<long long> visit(N, 0);
vector<vector<long long> > dp(N, vector<long long>(150, 0));
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m >> k;
  vector<vector<long long> > a(n, vector<long long>(m + 1));
  for (long long i = 0; i < n; i++) {
    cin >> a[i][0];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> a[i][j + 1];
  }
  sort(a.rbegin(), a.rend());
  dp[0][0] = a[0][0];
  for (long long j = 0; j < m; j++) {
    dp[0][(1 << j)] = a[0][j + 1];
  }
  for (long long i = 1; i < n; i++) {
    for (long long mask = 0; mask < (1 << m); mask++) {
      long long ex = 0;
      for (long long j = 0; j < m; j++) {
        if (mask & (1 << j)) {
          ex++;
        }
      }
      long long add = 0;
      if (i < k + ex) add = a[i][0];
      if (dp[i][mask] < dp[i - 1][mask] + add) {
        dp[i][mask] = dp[i - 1][mask] + add;
      }
      add = 0;
      for (long long j = 0; j < m; j++) {
        if (!(mask & (1 << j))) {
          if (dp[i][mask | (1 << j)] < dp[i - 1][mask] + a[i][j + 1] + add) {
            dp[i][mask | (1 << j)] = dp[i - 1][mask] + a[i][j + 1] + add;
          }
        }
      }
    }
  }
  long long ans = dp[n - 1][(1 << m) - 1];
  cout << ans;
}
