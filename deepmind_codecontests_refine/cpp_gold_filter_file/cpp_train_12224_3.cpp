#include <bits/stdc++.h>
using namespace std;
template <class T>
void mini(T& a, T b) {
  a = min(a, b);
}
template <class T>
void maxi(T& a, T b) {
  a = max(a, b);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  return out << a.first << " " << a.second;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, multiset<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> a) {
  for (auto& i : a) out << i << "\n";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, unordered_map<T1, T2> a) {
  for (auto& i : a) out << i << "\n";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, queue<T> a) {
  while (!a.empty()) {
    cout << a.front() << " ";
    a.pop();
  }
  return out;
}
template <class T>
ostream& operator<<(ostream& out, deque<T> a) {
  while (!a.empty()) {
    cout << a.front() << " ";
    a.pop_front();
  }
  return out;
}
template <class T>
void out(T a) {
  cout << a << endl;
}
template <class T1, class T2>
void out(T1 a, T2 b) {
  cout << a << " " << b << endl;
}
template <class T1, class T2, class T3>
void out(T1 a, T2 b, T2 c) {
  cout << a << " " << b << " " << c << endl;
}
void out() { cout << "OK" << endl; }
istream& operator>>(istream& in, __int128& a) {
  int64_t b;
  cin >> b;
  a = b;
  return in;
}
ostream& operator<<(ostream& out, const __int128 a) {
  unsigned __int128 b = a < 0 ? -a : a;
  char buf[128];
  char* c = end(buf);
  do {
    --c;
    *c = "0123456789"[b % 10];
    b /= 10;
  } while (b);
  if (a < 0) {
    --c;
    *c = '-';
  }
  int len = end(buf) - c;
  out.rdbuf()->sputn(c, len);
  return out;
}
template <int m>
struct mint {
  int x;
  mint(int64_t a = 0) {
    if (a < 0) a = a % m + m;
    if (a >= m) a %= m;
    x = a;
  }
  friend istream& operator>>(istream& in, mint& a) {
    int64_t y;
    cin >> y;
    a = y;
    return in;
  }
  friend ostream& operator<<(ostream& out, mint a) { return out << a.x; }
  explicit operator int() const { return x; }
  static int mod_inv(int a, int mod = m) {
    int g = mod, r = a, z = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      z -= q * y;
      swap(z, y);
    }
    return z < 0 ? z + mod : z;
  }
  mint inv() const { return mod_inv(x, m); }
  friend mint binpow(mint a, int64_t b) {
    mint res = 1;
    while (b) {
      if (b & 1) res *= a;
      b >>= 1;
      a *= a;
    }
    return res;
  }
  mint pow(int64_t b) const { return binpow(*this, b); }
  mint& operator+=(const mint& a) {
    x += a.x;
    if (x >= m) x -= m;
    return *this;
  }
  mint& operator-=(const mint& a) {
    x -= a.x;
    if (x < 0) x += m;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned mod = m) {
    return x % mod;
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n"
        : "=a"(quot), "=d"(rem)
        : "d"(x_high), "a"(x_low), "r"(mod));
    return rem;
  }
  mint& operator*=(const mint& a) {
    x = fast_mod((uint64_t)x * a.x);
    return *this;
  }
  mint& operator/=(const mint& a) { return *this *= a.inv(); }
  friend mint operator+(const mint& a, const mint& b) { return mint(a) += b; }
  friend mint operator-(const mint& a, const mint& b) { return mint(a) -= b; }
  friend mint operator*(const mint& a, const mint& b) { return mint(a) *= b; }
  friend mint operator/(const mint& a, const mint& b) {
    return mint(a) /= mint(b);
  }
  mint& operator++() {
    x = x == m - 1 ? 0 : x + 1;
    return *this;
  }
  mint& operator--() {
    x = x == 0 ? m - 1 : x - 1;
    return *this;
  }
  mint operator++(int) {
    mint a = *this;
    ++*this;
    return a;
  }
  mint operator--(int) {
    mint a = *this;
    --*this;
    return a;
  }
  mint operator-() const { return x ? m - x : 0; }
  bool operator==(const mint& a) const { return x == a.x; }
  bool operator!=(const mint& a) const { return x != a.x; }
};
const int p = 1e9 + 7;
__int128 gcd(__int128 a, __int128 b) {
  if (!b) return a;
  return gcd(b, a % b);
}
struct frac {
  __int128 x, y;
  void norm() {
    if (!x && !y) {
      x = 1;
      y = 0;
    }
    if (y < 0) {
      x *= -1;
      y *= -1;
    }
    __int128 d = gcd(x, y);
    if (d < 0) d *= -1;
    x /= d;
    y /= d;
  }
  frac(__int128 x_ = 0, __int128 y_ = 1) : x(x_), y(y_) { norm(); }
  friend istream& operator>>(istream& in, frac& a) {
    __int128 x;
    in >> x;
    a = {x, 1};
    return in;
  }
  friend ostream& operator<<(ostream& out, frac a) {
    return out << "(" << a.x << " / " << a.y << ")";
  }
  explicit operator long double() const { return (long double)x / y; }
  frac& operator+=(const frac& a) {
    x = x * a.y + a.x * y;
    y *= a.y;
    norm();
    return *this;
  }
  frac& operator-=(const frac& a) {
    x = x * a.y - a.x * y;
    y *= a.y;
    norm();
    return *this;
  }
  frac& operator*=(const frac& a) {
    x *= a.x;
    y *= a.y;
    norm();
    return *this;
  }
  frac& operator/=(const frac& a) {
    x *= a.y;
    y *= a.x;
    norm();
    return *this;
  }
  friend frac operator+(const frac& a, const frac& b) { return frac(a) += b; }
  friend frac operator-(const frac& a, const frac& b) { return frac(a) -= b; }
  friend frac operator*(const frac& a, const frac& b) { return frac(a) *= b; }
  friend frac operator/(const frac& a, const frac& b) { return frac(a) /= b; }
  frac operator-() const { return {-x, y}; }
  friend bool operator==(const frac& a, const frac& b) {
    return a.x == b.x && a.y == b.y;
  }
  friend bool operator!=(const frac& a, const frac& b) {
    return a.x != b.x || a.y != b.y;
  }
  friend bool operator<(const frac& a, const frac& b) {
    return a.x * b.y < a.y * b.x;
  }
  friend bool operator>(const frac& a, const frac& b) {
    return a.x * b.y > a.y * b.x;
  }
  friend bool operator<=(const frac& a, const frac& b) {
    return a.x * b.y <= a.y * b.x;
  }
  friend bool operator>=(const frac& a, const frac& b) {
    return a.x * b.y >= a.y * b.x;
  }
  friend frac sq(frac x) { return x * x; }
};
const int N = 1005;
complex<frac> a[N];
map<pair<frac, frac>, map<frac, int>> b;
void Solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    frac x = {A, B};
    frac y = {C, D};
    frac k = 1 / (sq(x) + sq(y));
    x *= k;
    y *= k;
    a[i] = {x, y};
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      complex<frac> m = a[i] + a[j];
      pair<frac, frac> M = {m.real(), m.imag()};
      complex<frac> v = a[i] - a[j];
      if (v.real() < 0)
        v = {-v.real(), -v.imag()};
      else if (v.real() == 0 && v.imag() < 0)
        v = {0, -v.imag()};
      frac f = v.imag() / v.real();
      b[M][f]++;
    }
  }
  mint<p> ans = 0;
  for (auto& it : b) {
    mint<p> cur = 1;
    mint<p> lol = 1;
    for (auto& it1 : it.second) {
      cur *= it1.second + 1;
      lol += it1.second;
    }
    cur -= lol;
    ans += cur;
  }
  out(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
