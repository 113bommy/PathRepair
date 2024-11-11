#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
ostream &operator<<(ostream &out, const vector<long long> &b) {
  for (auto k : b) out << k << ' ';
  return out;
}
const long long MOD = 1000000007;
const long long INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const long long MX = 1 << 18;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long c[MX];
long long dp[MX][20];
long long pws[20];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long done = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> c[i - done];
    if (c[i - done] == -1) {
      c[i - done] = 0;
      done = 1;
    }
    if (!done) c[i - done] = 0;
  }
  reverse(c, c + n - 1);
  pws[1] = n / 2;
  for (long long i = 2; i < 20; ++i) {
    pws[i] = pws[i - 1] / 2;
  }
  partial_sum(pws, pws + 20, pws);
  for (long long i = 0; i < MX; ++i)
    for (long long j = 0; j < 20; ++j) dp[i][j] = INF;
  dp[0][0] = 0;
  for (long long i = 0; i < n - 1; ++i) {
    for (long long j = 0; j < 19; ++j) {
      if (pws[j] >= i + 1) mine(dp[i + 1][j], dp[i][j]);
      if (pws[j + 1] >= i + 1) mine(dp[i + 1][j + 1], dp[i][j] + c[i]);
    }
  }
  cout << dp[n - 1][63 - __builtin_clzll(n)] << '\n';
}
