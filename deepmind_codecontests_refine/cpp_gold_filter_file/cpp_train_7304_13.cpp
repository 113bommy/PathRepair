#include <bits/stdc++.h>
using namespace std;
mt19937 rng(static_cast<unsigned int>(
    chrono::steady_clock::now().time_since_epoch().count()));
template <typename num_t>
inline void add_mod(num_t& a, const int& b, const int& m) {
  a = (a + b) % m;
  if (a >= m) a -= m;
  if (a < 0) a += m;
}
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) {
  return a < b ? a = b, true : false;
}
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) {
  return a > b ? a = b, true : false;
}
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) {
  return !lhs ? rhs : gcd(rhs % lhs, lhs);
}
template <typename num_t>
num_t pw(num_t n, num_t k, const num_t& mod) {
  if (k == -1) k = mod - 2;
  num_t res = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res % mod;
}
const int inf = 1e9 + 7;
const int mod = 998244353;
const long long ll_inf = 9ll * inf * inf + 7;
const int MAX_N = 1000 + 7;
void solve() {
  int n, p, k;
  cin >> n >> p >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  map<long long, long long> calc;
  for (auto x : a) {
    long long temp = pw(x, 4, p);
    add_mod(temp, -1ll * k * x % p, p);
    calc[temp]++;
  }
  long long res = 0;
  for (auto p : calc) {
    res += (long long)p.second * (p.second - 1) / 2;
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
