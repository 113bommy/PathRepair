#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << "=" << a << ", ";
  err(++it, args...);
}
const long long inf = 1LL << 60;
const long long md = 1000000007;
double dp[205][205][205];
void solve() {
  long long n, l, k;
  cin >> n >> l >> k;
  double p[n];
  for (long long i = 0; i < n; i++) {
    double x;
    cin >> x;
    p[i] = x / 100;
  }
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i]++;
  }
  dp[0][0][k] = 1;
  for (long long i = 0; i < n; i++) {
    for (long long w = 0; w <= n; w++) {
      for (long long j = 0; j <= 200; j++) {
        long long r = min(200LL, j + a[i]);
        dp[i + 1][w + 1][r] += dp[i][w][j] * p[i];
        dp[i + 1][w][j] += dp[i][w][j] * (1 - p[i]);
      }
    }
  }
  cout << setprecision(10) << fixed;
  double ans = 0;
  for (long long w = l; w <= n; w++) {
    for (long long i = l; i <= 200; i++) {
      ans += dp[n][w][i];
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
    cout << '\n';
  }
}
