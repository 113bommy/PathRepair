#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T maxs(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T mins(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T>
class matrix {
 public:
  vector<vector<T>> val;
  long long n;
  matrix<T>(long long size) {
    n = size;
    val.resize(n);
    for (long long i = 0; i < n; i++) val[i].resize(n);
  }
  matrix<T> operator+(const matrix<T> &) const;
  matrix<T> operator-(const matrix<T> &) const;
  matrix<T> &operator=(const matrix<T> &b) {
    val = b.val;
    n = b.n;
    return *this;
  }
  void set(long long first) {
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        val[i][j] = first;
      }
    }
  }
  void print() {
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        cout << val[i][j] << " ";
      }
      cout << "\n";
    }
  }
  matrix<T> mul(T a) {
    matrix<T> ans(this->n);
    for (long long i = 0; i < this->n; i++) {
      for (long long j = 0; j < this->n; j++) {
        ans.val[i][j] = a * this->val[i][j];
      }
    }
    return ans;
  }
  matrix<T> operator*(const matrix<T> &b) const {
    matrix<T> ans(b.n);
    for (long long i = 0; i < b.n; i++) {
      for (long long j = 0; j < b.n; j++) {
        for (long long k = 0; k < b.n; k++) {
          ans.val[i][j] += this->val[i][k] * b.val[k][j];
        }
      }
    }
    return ans;
  }
  matrix<T> identity(long long N) {
    matrix<T> ans(N);
    for (long long i = 0; i < N; i++) {
      ans.val[i][i] = 1;
    }
    return ans;
  }
  matrix<T> matexpo(matrix<T> a, long long n) {
    if (n == 0) {
      return identity(a.n);
    }
    if (n == 1) return a;
    matrix<T> first = matexpo(a, n / 2);
    matrix<T> r = first * first;
    if (n & 1) r = r * a;
    return r;
  }
};
const long long MOD = 1000000007;
struct mod_int {
  long long val;
  mod_int(long long v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static long long mod_inv(long long a, long long m = MOD) {
    long long g = m, r = a, first = 0, second = 1;
    while (r != 0) {
      long long q = g / r;
      g %= r;
      swap(g, r);
      first -= q * second;
      swap(first, second);
    }
    return first < 0 ? first + m : first;
  }
  explicit operator long long() const { return val; }
  mod_int &operator+=(const mod_int &other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  mod_int &operator-=(const mod_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t first, unsigned m = MOD) {
    return first % m;
    unsigned x_high = first >> 32, x_low = (unsigned)first;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  mod_int &operator*=(const mod_int &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  mod_int &operator/=(const mod_int &other) { return *this *= other.inv(); }
  friend mod_int operator+(const mod_int &a, const mod_int &b) {
    return mod_int(a) += b;
  }
  friend mod_int operator-(const mod_int &a, const mod_int &b) {
    return mod_int(a) -= b;
  }
  friend mod_int operator*(const mod_int &a, const mod_int &b) {
    return mod_int(a) *= b;
  }
  friend mod_int operator/(const mod_int &a, const mod_int &b) {
    return mod_int(a) /= b;
  }
  mod_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  mod_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  mod_int operator++(int32_t) {
    mod_int before = *this;
    ++*this;
    return before;
  }
  mod_int operator--(int32_t) {
    mod_int before = *this;
    --*this;
    return before;
  }
  mod_int operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const mod_int &other) const { return val == other.val; }
  bool operator!=(const mod_int &other) const { return val != other.val; }
  mod_int inv() const { return mod_inv(val); }
  mod_int pow(long long p) const {
    assert(p >= 0);
    mod_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &stream, const mod_int &m) {
    return stream << m.val;
  }
  friend istream &operator>>(istream &stream, mod_int &m) {
    return stream >> m.val;
  }
};
long long solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  long long z = 0;
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
    z += (!a[i]);
  }
  long long c = 0;
  for (long long i = 1; i < z + 1; i++) {
    c += (!a[i]);
  }
  matrix<mod_int> m(z + 1);
  for (long long j = 1; j < z + 1; j++) {
    m.val[j][j] = n * (n - 1) / 2 - j * (n - 2 * z + j) - (z - j) * (z - j);
    if (j > 1) m.val[j][j - 1] = j * (n - 2 * z + j);
    if (j < z) m.val[j][j + 1] = (z - j) * (z - j);
  }
  mod_int t = n * (n - 1) / 2;
  t = t.pow(k);
  m = m.matexpo(m, k);
  cout << m.val[c][z] / t << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
