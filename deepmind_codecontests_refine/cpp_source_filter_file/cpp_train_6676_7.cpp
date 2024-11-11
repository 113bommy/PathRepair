#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
struct Mint {
  int val;
  Mint(long long v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static int mod_inv(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  Mint &operator+=(const Mint &other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  Mint &operator-=(const Mint &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return x % m;
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  Mint &operator*=(const Mint &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  Mint &operator/=(const Mint &other) { return *this *= other.inv(); }
  friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
  friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
  friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
  friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
  Mint &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  Mint &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  Mint operator++(int32_t) {
    Mint before = *this;
    ++*this;
    return before;
  }
  Mint operator--(int32_t) {
    Mint before = *this;
    --*this;
    return before;
  }
  Mint operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const Mint &other) const { return val == other.val; }
  bool operator!=(const Mint &other) const { return val != other.val; }
  Mint inv() const { return mod_inv(val); }
  Mint power(long long p) const {
    assert(p >= 0);
    Mint a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &stream, const Mint &m) {
    return stream << m.val;
  }
  friend istream &operator>>(istream &stream, Mint &m) {
    return stream >> m.val;
  }
};
namespace algebra {
const int inf = 1e9;
const int magic = 200;
namespace NTT {
vector<Mint> roots = {0, 1};
vector<int> bit_reverse;
int max_size = -1;
Mint root;
bool is_power_of_two(int n) { return (n & (n - 1)) == 0; }
int round_up_power_two(int n) {
  while (n & (n - 1)) n = (n | (n - 1)) + 1;
  return max(n, 1);
}
int get_length(int n) {
  assert(is_power_of_two(n));
  return __builtin_ctz(n);
}
void bit_reorder(int n, vector<Mint> &values) {
  if ((int)bit_reverse.size() != n) {
    bit_reverse.assign(n, 0);
    int length = get_length(n);
    for (int i = 0; i < n; i++)
      bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
  }
  for (int i = 0; i < n; i++)
    if (i < bit_reverse[i]) swap(values[i], values[bit_reverse[i]]);
}
void find_root() {
  max_size = 1 << __builtin_ctz(MOD - 1);
  root = 2;
  while (!(root.power(max_size) == 1 && root.power(max_size / 2) != 1)) root++;
}
void prepare_roots(int n) {
  if (max_size < 0) find_root();
  assert(n <= max_size);
  if ((int)roots.size() >= n) return;
  int length = get_length(roots.size());
  roots.resize(n);
  while (1 << length < n) {
    Mint z = root.power(max_size >> (length + 1));
    for (int i = 1 << (length - 1); i < 1 << length; i++) {
      roots[2 * i] = roots[i];
      roots[2 * i + 1] = roots[i] * z;
    }
    length++;
  }
}
void fft_iterative(int N, vector<Mint> &values) {
  assert(is_power_of_two(N));
  prepare_roots(N);
  bit_reorder(N, values);
  for (int n = 1; n < N; n *= 2)
    for (int start = 0; start < N; start += 2 * n)
      for (int i = 0; i < n; i++) {
        Mint even = values[start + i];
        Mint odd = values[start + n + i] * roots[n + i];
        values[start + n + i] = even - odd;
        values[start + i] = even + odd;
      }
}
const int FFT_CUTOFF = magic;
vector<Mint> mod_multiply(vector<Mint> left, vector<Mint> right) {
  int n = left.size();
  int m = right.size();
  if (min(n, m) < FFT_CUTOFF) {
    const uint64_t ULL_BOUND =
        numeric_limits<uint64_t>::max() - (uint64_t)MOD * MOD;
    vector<uint64_t> result(n + m - 1, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        result[i + j] += (uint64_t)((int)left[i]) * ((int)right[j]);
        if (result[i + j] > ULL_BOUND) result[i + j] %= MOD;
      }
    for (uint64_t &x : result)
      if (x >= MOD) x %= MOD;
    return vector<Mint>(result.begin(), result.end());
  }
  int N = round_up_power_two(n + m - 1);
  left.resize(N);
  right.resize(N);
  bool equal = left == right;
  fft_iterative(N, left);
  if (equal)
    right = left;
  else
    fft_iterative(N, right);
  Mint inv_N = Mint(N).inv();
  for (int i = 0; i < N; i++) left[i] *= right[i] * inv_N;
  reverse(left.begin() + 1, left.end());
  fft_iterative(N, left);
  left.resize(n + m - 1);
  return left;
}
template <typename T>
void mul(vector<T> &a, const vector<T> &b) {
  a = mod_multiply(a, b);
}
}  // namespace NTT
template <typename T>
T bpow(T x, size_t n) {
  return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1);
}
template <typename T>
T bpow(T x, size_t n, T m) {
  return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m)
           : T(1);
}
template <typename T>
T gcd(const T &a, const T &b) {
  return b == T(0) ? a : gcd(b, a % b);
}
template <typename T>
T nCr(T n, int r) {
  T res(1);
  for (int i = 0; i < r; i++) {
    res *= (n - T(i));
    res /= (i + 1);
  }
  return res;
}
template <typename T>
struct poly {
  vector<T> a;
  void normalize() {
    while (!a.empty() && a.back() == T(0)) {
      a.pop_back();
    }
  }
  poly() {}
  poly(T a0) : a{a0} { normalize(); }
  poly(vector<T> t) : a(t) { normalize(); }
  poly operator+=(const poly &t) {
    a.resize(max(a.size(), t.a.size()));
    for (size_t i = 0; i < t.a.size(); i++) {
      a[i] += t.a[i];
    }
    normalize();
    return *this;
  }
  poly operator-=(const poly &t) {
    a.resize(max(a.size(), t.a.size()));
    for (size_t i = 0; i < t.a.size(); i++) {
      a[i] -= t.a[i];
    }
    normalize();
    return *this;
  }
  poly operator+(const poly &t) const { return poly(*this) += t; }
  poly operator-(const poly &t) const { return poly(*this) -= t; }
  poly mod_xk(size_t k) const {
    k = min(k, a.size());
    return vector<T>(begin(a), begin(a) + k);
  }
  poly mul_xk(size_t k) const {
    poly res(*this);
    res.a.insert(begin(res.a), k, 0);
    return res;
  }
  poly div_xk(size_t k) const {
    k = min(k, a.size());
    return vector<T>(begin(a) + k, end(a));
  }
  poly substr(size_t l, size_t r) const {
    l = min(l, a.size());
    r = min(r, a.size());
    return vector<T>(begin(a) + l, begin(a) + r);
  }
  poly inv(size_t n) const {
    assert(!is_zero());
    poly ans = a[0].inv();
    size_t a = 1;
    while (a < n) {
      poly C = (ans * mod_xk(2 * a)).substr(a, 2 * a);
      ans -= (ans * C).mod_xk(a).mul_xk(a);
      a *= 2;
    }
    return ans.mod_xk(n);
  }
  poly operator*=(const poly &t) {
    NTT::mul(a, t.a);
    normalize();
    return *this;
  }
  poly operator*(const poly &t) const { return poly(*this) *= t; }
  poly reverse(size_t n, bool rev = 0) const {
    poly res(*this);
    if (rev) {
      res.a.resize(max(n, res.a.size()));
    }
    std::reverse(res.a.begin(), res.a.end());
    return res.mod_xk(n);
  }
  pair<poly, poly> divmod_slow(const poly &b) const {
    vector<T> A(a);
    vector<T> res;
    while (A.size() >= b.a.size()) {
      res.push_back(A.back() / b.a.back());
      if (res.back() != T(0)) {
        for (size_t i = 0; i < b.a.size(); i++) {
          A[A.size() - i - 1] -= res.back() * b.a[b.a.size() - i - 1];
        }
      }
      A.pop_back();
    }
    std::reverse(begin(res), end(res));
    return {res, A};
  }
  pair<poly, poly> divmod(const poly &b) const {
    if (deg() < b.deg()) {
      return {poly{0}, *this};
    }
    int d = deg() - b.deg();
    if (min(d, b.deg()) < magic) {
      return divmod_slow(b);
    }
    poly D = (reverse(d + 1) * b.reverse(d + 1).inv(d + 1))
                 .mod_xk(d + 1)
                 .reverse(d + 1, 1);
    return {D, *this - D * b};
  }
  poly operator/(const poly &t) const { return divmod(t).first; }
  poly operator%(const poly &t) const { return divmod(t).second; }
  poly operator/=(const poly &t) { return *this = divmod(t).first; }
  poly operator%=(const poly &t) { return *this = divmod(t).second; }
  poly operator*=(const T &x) {
    for (auto &it : a) {
      it *= x;
    }
    normalize();
    return *this;
  }
  poly operator/=(const T &x) {
    for (auto &it : a) {
      it /= x;
    }
    normalize();
    return *this;
  }
  poly operator*(const T &x) const { return poly(*this) *= x; }
  poly operator/(const T &x) const { return poly(*this) /= x; }
  void print() const {
    for (auto it : a) {
      cout << it << ' ';
    }
    cout << endl;
  }
  T eval(T x) const {
    T res(0);
    for (int i = int(a.size()) - 1; i >= 0; i--) {
      res *= x;
      res += a[i];
    }
    return res;
  }
  T &lead() { return a.back(); }
  int deg() const { return a.empty() ? -inf : a.size() - 1; }
  bool is_zero() const { return a.empty(); }
  T operator[](int idx) const {
    return idx >= (int)a.size() || idx < 0 ? T(0) : a[idx];
  }
  T &coef(size_t idx) { return a[idx]; }
  bool operator==(const poly &t) const { return a == t.a; }
  bool operator!=(const poly &t) const { return a != t.a; }
  poly deriv() {
    vector<T> res;
    for (int i = 1; i <= deg(); i++) {
      res.push_back(T(i) * a[i]);
    }
    return res;
  }
  poly integr() {
    vector<T> res = {0};
    for (int i = 0; i <= deg(); i++) {
      res.push_back(a[i] / T(i + 1));
    }
    return res;
  }
  size_t leading_xk() const {
    if (is_zero()) {
      return inf;
    }
    int res = 0;
    while (a[res] == T(0)) {
      res++;
    }
    return res;
  }
  poly log(size_t n) {
    assert(a[0] == T(1));
    return (deriv().mod_xk(n) * inv(n)).integr().mod_xk(n);
  }
  poly exp(size_t n) {
    if (is_zero()) {
      return T(1);
    }
    assert(a[0] == T(0));
    poly ans = T(1);
    size_t a = 1;
    while (a < n) {
      poly C = ans.log(2 * a).div_xk(a) - substr(a, 2 * a);
      ans -= (ans * C).mod_xk(a).mul_xk(a);
      a *= 2;
    }
    return ans.mod_xk(n);
  }
  poly pow_slow(size_t k, size_t n) {
    return k ? k % 2 ? (*this * pow_slow(k - 1, n)).mod_xk(n)
                     : (*this * *this).mod_xk(n).pow_slow(k / 2, n)
             : T(1);
  }
  poly pow(size_t k, size_t n) {
    if (is_zero()) {
      return *this;
    }
    if (k < magic) {
      return pow_slow(k, n);
    }
    int i = leading_xk();
    T j = a[i];
    poly t = div_xk(i) / j;
    return bpow(j, k) * (t.log(n) * T(k)).exp(n).mul_xk(i * k).mod_xk(n);
  }
  poly mulx(T x) {
    T cur = 1;
    poly res(*this);
    for (int i = 0; i <= deg(); i++) {
      res.coef(i) *= cur;
      cur *= x;
    }
    return res;
  }
  poly mulx_sq(T x) {
    T cur = x;
    T total = 1;
    T xx = x * x;
    poly res(*this);
    for (int i = 0; i <= deg(); i++) {
      res.coef(i) *= total;
      total *= cur;
      cur *= xx;
    }
    return res;
  }
  vector<T> chirpz_even(T z, int n) {
    int m = deg();
    if (is_zero()) {
      return vector<T>(n, 0);
    }
    vector<T> vv(m + n);
    T zi = z.inv();
    T zz = zi * zi;
    T cur = zi;
    T total = 1;
    for (int i = 0; i <= max(n - 1, m); i++) {
      if (i <= m) {
        vv[m - i] = total;
      }
      if (i < n) {
        vv[m + i] = total;
      }
      total *= cur;
      cur *= zz;
    }
    poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
    vector<T> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = w[i];
    }
    return res;
  }
  vector<T> chirpz(T z, int n) {
    auto even = chirpz_even(z, (n + 1) / 2);
    auto odd = mulx(z).chirpz_even(z, n / 2);
    vector<T> ans(n);
    for (int i = 0; i < n / 2; i++) {
      ans[2 * i] = even[i];
      ans[2 * i + 1] = odd[i];
    }
    if (n % 2 == 1) {
      ans[n - 1] = even.back();
    }
    return ans;
  }
  template <typename iter>
  vector<T> eval(vector<poly> &tree, int v, iter l, iter r) {
    if (r - l == 1) {
      return {eval(*l)};
    } else {
      auto m = l + (r - l) / 2;
      auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, m);
      auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, m, r);
      A.insert(end(A), begin(B), end(B));
      return A;
    }
  }
  vector<T> eval(vector<T> x) {
    int n = x.size();
    if (is_zero()) {
      return vector<T>(n, T(0));
    }
    vector<poly> tree(4 * n);
    build(tree, 1, begin(x), end(x));
    return eval(tree, 1, begin(x), end(x));
  }
  template <typename iter>
  poly inter(vector<poly> &tree, int v, iter l, iter r, iter ly, iter ry) {
    if (r - l == 1) {
      return {*ly / a[0]};
    } else {
      auto m = l + (r - l) / 2;
      auto my = ly + (ry - ly) / 2;
      auto A = (*this % tree[2 * v]).inter(tree, 2 * v, l, m, ly, my);
      auto B = (*this % tree[2 * v + 1]).inter(tree, 2 * v + 1, m, r, my, ry);
      return A * tree[2 * v + 1] + B * tree[2 * v];
    }
  }
};
template <typename T>
poly<T> operator*(const T &a, const poly<T> &b) {
  return b * a;
}
template <typename T>
poly<T> xk(int k) {
  return poly<T>{1}.mul_xk(k);
}
template <typename T>
T resultant(poly<T> a, poly<T> b) {
  if (b.is_zero()) {
    return 0;
  } else if (b.deg() == 0) {
    return bpow(b.lead(), a.deg());
  } else {
    int pw = a.deg();
    a %= b;
    pw -= a.deg();
    T mul = bpow(b.lead(), pw) * T((b.deg() & a.deg() & 1) ? -1 : 1);
    T ans = resultant(b, a);
    return ans * mul;
  }
}
template <typename iter>
poly<typename iter::value_type> kmul(iter L, iter R) {
  if (R - L == 1) {
    return vector<typename iter::value_type>{-*L, 1};
  } else {
    iter M = L + (R - L) / 2;
    return kmul(L, M) * kmul(M, R);
  }
}
template <typename T, typename iter>
poly<T> build(vector<poly<T>> &res, int v, iter L, iter R) {
  if (R - L == 1) {
    return res[v] = vector<T>{-*L, 1};
  } else {
    iter M = L + (R - L) / 2;
    return res[v] = build(res, 2 * v, L, M) * build(res, 2 * v + 1, M, R);
  }
}
template <typename T>
poly<T> inter(vector<T> x, vector<T> y) {
  int n = x.size();
  vector<poly<T>> tree(4 * n);
  return build(tree, 1, begin(x), end(x))
      .deriv()
      .inter(tree, 1, begin(x), end(x), begin(y), end(y));
}
};  // namespace algebra
using namespace algebra;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Mint> c(10, Mint(0));
  int mx = 0;
  for (int x, i = 0; i < m; i++) {
    cin >> x;
    mx = max(mx, x);
    c[x]++;
  }
  poly<Mint> C(c);
  poly<Mint> ret = C.pow(n >> 1, mx * (n >> 1));
  Mint ans;
  for (Mint &x : ret.a) ans = ans + x * x;
  cout << ans << '\n';
}
