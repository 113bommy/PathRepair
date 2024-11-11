#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
template <const int &MOD>
struct _m_int {
  int val;
  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
  _m_int(uint64_t v) {
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
  _m_int(int v) : _m_int(int64_t(v)) {}
  _m_int(unsigned v) : _m_int(uint64_t(v)) {}
  explicit operator int() const { return val; }
  explicit operator unsigned() const { return val; }
  explicit operator int64_t() const { return val; }
  explicit operator uint64_t() const { return val; }
  explicit operator double() const { return val; }
  explicit operator long double() const { return val; }
  _m_int &operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  _m_int &operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return unsigned(x % m);
    unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  _m_int &operator*=(const _m_int &other) {
    val = fast_mod(uint64_t(val) * other.val);
    return *this;
  }
  _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }
  friend _m_int operator+(const _m_int &a, const _m_int &b) {
    return _m_int(a) += b;
  }
  friend _m_int operator-(const _m_int &a, const _m_int &b) {
    return _m_int(a) -= b;
  }
  friend _m_int operator*(const _m_int &a, const _m_int &b) {
    return _m_int(a) *= b;
  }
  friend _m_int operator/(const _m_int &a, const _m_int &b) {
    return _m_int(a) /= b;
  }
  _m_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  _m_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  _m_int operator++(int) {
    _m_int before = *this;
    ++*this;
    return before;
  }
  _m_int operator--(int) {
    _m_int before = *this;
    --*this;
    return before;
  }
  _m_int operator-() const { return val == 0 ? 0 : MOD - val; }
  friend bool operator==(const _m_int &a, const _m_int &b) {
    return a.val == b.val;
  }
  friend bool operator!=(const _m_int &a, const _m_int &b) {
    return a.val != b.val;
  }
  friend bool operator<(const _m_int &a, const _m_int &b) {
    return a.val < b.val;
  }
  friend bool operator>(const _m_int &a, const _m_int &b) {
    return a.val > b.val;
  }
  friend bool operator<=(const _m_int &a, const _m_int &b) {
    return a.val <= b.val;
  }
  friend bool operator>=(const _m_int &a, const _m_int &b) {
    return a.val >= b.val;
  }
  static const int SAVE_INV = int(1e6) + 5;
  static _m_int save_inv[SAVE_INV];
  static void prepare_inv() {
    for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1) assert(MOD % p != 0);
    save_inv[0] = 0;
    save_inv[1] = 1;
    for (int i = 2; i < SAVE_INV; i++)
      save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
  }
  _m_int inv() const {
    if (save_inv[1] == 0) prepare_inv();
    if (val < SAVE_INV) return save_inv[val];
    _m_int product = 1;
    int v = val;
    while (v >= SAVE_INV) {
      product *= MOD - MOD / v;
      v = MOD % v;
    }
    return product * save_inv[v];
  }
  _m_int pow(int64_t p) const {
    if (p < 0) return inv().pow(-p);
    _m_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      p >>= 1;
      if (p > 0) a *= a;
    }
    return result;
  }
  friend ostream &operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};
template <const int &MOD>
_m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
const int MOD = 998244353;
using mint = _m_int<MOD>;
const int MXN = 1e5 + 5, INF = 1e9 + 5;
void solve() {
  int N;
  cin >> N;
  vector<int> loc(N + 1), teleport(N + 1), state(N + 1);
  for (int i = 1; i <= N; i++) cin >> loc[i] >> teleport[i] >> state[i];
  loc[0] = loc[1];
  teleport[0] = teleport[1];
  state[0] = state[1];
  vector<int> closest(N + 1);
  for (int i = 1; i <= N; i++)
    closest[i] =
        upper_bound((loc).begin(), (loc).end(), teleport[i]) - loc.begin();
  closest[0] = closest[1];
  vector<mint> time_taken(N + 1, 0);
  mint ans = loc[1];
  for (int i = 1; i <= N; i++) {
    time_taken[i] = loc[closest[i]] - teleport[i] + time_taken[i - 1] -
                    time_taken[closest[i] - 1];
    ans += loc[i] - loc[i - 1];
    if (state[i] == 1) ans += time_taken[i];
    if (i < N) time_taken[i] += loc[i + 1] - loc[i];
    time_taken[i] += time_taken[i - 1];
  }
  cout << ans + 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int TC = 1;
  while (TC--) solve();
}
