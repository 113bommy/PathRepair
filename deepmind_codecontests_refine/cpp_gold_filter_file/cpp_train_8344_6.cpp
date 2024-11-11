#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;
inline void yes() {
  cout << "Yes" << '\n';
  exit(0);
}
inline void no() {
  cout << "No" << '\n';
  exit(0);
}
inline i64 gcd(i64 a, i64 b) {
  if (min(a, b) == 0) return max(a, b);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(16);
  solve();
  return 0;
}
template <typename T>
class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T>
class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T>
inline void amax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
inline void amin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
inline T power(T x, i64 n, T e = 1) {
  T r = e;
  while (n > 0) {
    if (n & 1) r *= x;
    x *= x;
    n >>= 1;
  }
  return r;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < int(v.size()); i++) {
    if (i) os << ' ';
    os << v[i];
  }
  return os;
}
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(i64 a) {
    x = a % mod;
    if (x < 0) x += mod;
  }
  ModInt &operator+=(ModInt that) {
    x = (x + that.x) % mod;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    x = (x + mod - that.x) % mod;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    x = (i64)x * that.x % mod;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt operator-() { return ModInt(-this->x); }
  friend ostream &operator<<(ostream &os, ModInt m) { return os << m.x; }
  ModInt inverse() {
    int a = x, b = mod, u = 1, v = 0;
    while (b) {
      int t = a / b;
      a -= t * b;
      u -= t * v;
      swap(a, b);
      swap(u, v);
    }
    return ModInt(u);
  }
  ModInt operator+(ModInt that) { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) { return ModInt(*this) /= that; }
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  bool operator<(ModInt that) const { return x < that.x; }
  bool operator<=(ModInt that) const { return x <= that.x; }
  bool operator>(ModInt that) const { return x > that.x; }
  bool operator>=(ModInt that) const { return x >= that.x; }
};
using mint = ModInt<1000000007>;
using eint = ModInt<1000000006>;
vi32 prime_list(i32 n) {
  vi32 primes;
  vector<bool> f(n, true);
  f[0] = f[1] = false;
  for (int i = int(2); i < int(n); i++) {
    if (!f[i]) continue;
    primes.push_back(i);
    for (int j = i * 2; j < n; j += i) {
      f[j] = false;
    }
  }
  return primes;
}
template <typename T>
struct Matrix {
  vector<vector<T>> v;
  int r, c;
  Matrix(int r, int c, T d) : r(r), c(c) {
    v = vector<vector<T>>(r, vector<T>(c, d));
  }
  vector<T> &operator[](int x) { return v[x]; }
  Matrix<T> operator*=(Matrix<T> that) {
    assert(c == that.r);
    auto ret = Matrix<T>(r, that.c, 0);
    for (int i = 0; i < int(r); i++)
      for (int j = 0; j < int(that.c); j++)
        for (int k = 0; k < int(c); k++) {
          ret[i][j] += v[i][k] * that[k][j];
        }
    return *this = ret;
  }
  Matrix<T> operator*(Matrix<T> that) { return *this *= that; }
  Matrix<T> pow(i64 n) {
    assert(r == c);
    auto e = Matrix<T>(r, c, 0);
    for (int i = 0; i < int(r); i++) e[i][i] = 1;
    return power(*this, n, e);
  }
};
void solve() {
  auto plist = prime_list(100000);
  unordered_set<int> primes;
  i64 N, F1, F2, F3, C;
  cin >> N >> F1 >> F2 >> F3 >> C;
  vector<map<int, eint>> f(4);
  function<void(i64, int)> check = [&](i64 n, int x) {
    for (auto &p : plist) {
      if (n % p == 0) primes.insert(p);
      while (n % p == 0) f[x][p] += 1, n /= p;
    }
    if (n != 1) {
      primes.insert(n);
      f[x][n] += 1;
    }
  };
  check(C, 0);
  check(F1, 1);
  check(F2, 2);
  check(F3, 3);
  for (auto &p : f[0]) f[1][p.first] += p.second * 1;
  for (auto &p : f[0]) f[2][p.first] += p.second * 2;
  for (auto &p : f[0]) f[3][p.first] += p.second * 3;
  for (auto &p : f[0]) f[0][p.first] = p.second * N;
  auto m = Matrix<eint>(3, 3, 0ll);
  m[1][0] = 1ll;
  m[2][1] = 1ll;
  m[0][2] = 1ll;
  m[1][2] = 1ll;
  m[2][2] = 1ll;
  m = m.pow(N - 3);
  map<int, eint> ans;
  for (auto &p : primes) {
    auto t = Matrix<eint>(1, 3, 0ll);
    t[0][0] = f[1][p];
    t[0][1] = f[2][p];
    t[0][2] = f[3][p];
    auto r = t * m;
    ans[p] = r[0][2] - f[0][p];
  }
  mint res = 1;
  for (auto &a : ans) {
    res *= power((mint)a.first, a.second.x);
  }
  cout << res << '\n';
}
