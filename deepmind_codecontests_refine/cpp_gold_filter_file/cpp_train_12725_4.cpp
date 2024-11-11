#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, T2 y) {
  if (x < y) x = y;
}
ostream &operator<<(ostream &a, const vector<long long> &b) {
  for (auto k : b) cout << k << ' ';
  return a;
}
const long long MOD = 998244353;
const long long INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const long long MX = 200010;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long pw(long long a, long long b) {
  if (b == 0) return 1;
  long long res = pw(a, b / 2);
  res = res * res % MOD;
  if (b & 1) res = res * a % MOD;
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  long long x = r - l + 1;
  if (n % 2 && m % 2) {
    cout << pw(x, n * m);
  } else {
    if (x % 2) {
      cout << (pw(x, n * m) + 1) * pw(2, MOD - 2) % MOD;
    } else {
      cout << pw(x, n * m) * pw(2, MOD - 2) % MOD;
    }
  }
}
