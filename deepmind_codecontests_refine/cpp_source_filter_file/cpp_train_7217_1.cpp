#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int d8x[8] = {+1, +1, +1, 0, 0, -1, -1, -1};
int d8y[8] = {+1, 0, -1, +1, -1, +1, 0, -1};
int d4x[4] = {1, 0, 0, -1};
int d4y[4] = {0, -1, 1, 0};
long long power(long long x, long long y) {
  long long fk = 1;
  x = x;
  while (y > 0) {
    if (y & 1) fk = (fk * x);
    y = y >> 1;
    x = (x * x);
  }
  return fk;
}
long long sqr(long long x) { return x * x; }
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <class T>
inline void chmax(T &x, T y) {
  x = max((x), (y));
}
template <class T>
inline void chmin(T &x, T y) {
  x = min((x), (y));
}
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T powm(T a, T b, long long m) {
  T cnt = 1;
  while (b > 0) {
    if (b % 2 == 1) cnt = (cnt * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return cnt % m;
}
long long ncr(long long n, long long r) {
  long long fk = 1;
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    fk *= (n - i);
    fk /= (i + 1);
  }
  return fk;
}
const int MOD = 998244353;
const int N = 19;
int n;
long double a[N][N];
long double dp[1 << 18];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  dp[(1 << n) - 1] = 1.0;
  for (int mask = (1 << n) - 1; mask; mask--) {
    int tot = __builtin_popcount(mask);
    if (tot < 2) continue;
    long double ways_p = 2.0 / tot / (tot - 1);
    for (int i = 0; i < n; ++i) {
      if (!((mask >> i) & 1)) continue;
      for (int j = i + 1; j < n; ++j) {
        if (!((mask >> j) & 1)) continue;
        dp[mask ^ (1 << j)] = a[i][j] * dp[mask] * ways_p;
        dp[mask ^ (1 << i)] = a[j][i] * dp[mask] * ways_p;
      }
    }
  }
  cout << fixed << setprecision(7);
  for (int i = 0; i < n; ++i) {
    cout << dp[(1 << i)] << " ";
  }
}
int32_t main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
  return 0;
}
