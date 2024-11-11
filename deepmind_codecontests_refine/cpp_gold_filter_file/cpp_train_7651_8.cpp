#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 10;
const long double eps = 1e-9;
const long double pi = acos(-1);
inline void solve(), read();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
const long long MAXN = 31, MAXK = 51;
long long t;
long long dp[MAXN][MAXN][MAXK];
long long go(long long n, long long m, long long k) {
  if (dp[n][m][k]) {
    return dp[n][m][k];
  }
  if (!k) {
    return 0;
  }
  if (n * m == k) {
    return 0;
  }
  dp[n][m][k] = inf;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j <= k; j++) {
      (dp[n][m][k]) =
          ((dp[n][m][k]) > (go(i, m, j) + m * m + go(n - i, m, k - j)))
              ? (go(i, m, j) + m * m + go(n - i, m, k - j))
              : (dp[n][m][k]);
    }
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 0; j <= k; j++) {
      (dp[n][m][k]) =
          ((dp[n][m][k]) > (go(n, i, j) + n * n + go(n, m - i, k - j)))
              ? (go(n, i, j) + n * n + go(n, m - i, k - j))
              : (dp[n][m][k]);
    }
  }
  return dp[n][m][k];
}
inline void solve() {}
inline void read() {
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long ans = go(n, m, k);
    cout << ans << "\n";
  }
}
