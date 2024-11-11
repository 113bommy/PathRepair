#include <bits/stdc++.h>
template <typename T>
T gcd(T a, T b) {
  return ((a % b == 0) ? b : gcd(b, a % b));
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 998244353;
namespace Problem {
using namespace std;
template <long long Mod = MOD>
class Modint {
 public:
  long long v;
  Modint(const Modint &x) { v = x.v; }
  explicit Modint(int x) {
    if (x < 0 or Mod <= x) x %= Mod;
    if (x < 0) x += Mod;
    v = x;
  }
  explicit Modint(long long x) {
    if (x < 0 or Mod <= x) x %= Mod;
    if (x < 0) x += Mod;
    v = x;
  }
  explicit Modint(unsigned x) {
    if (Mod <= x) x %= Mod;
    v = x;
  }
  explicit Modint(unsigned long long x) {
    if (Mod <= x) x %= Mod;
    v = x;
  }
  template <typename T>
  explicit Modint(T x) {
    if (x < 0 or Mod <= x) x %= Mod;
    v = x;
  }
  Modint() : v(0) {}
  long long get() const { return v; }
  Modint mpow(Modint &n) const { return mpow(n.v); }
  Modint mpow(long long n) const {
    long long i = 1, p = v;
    Modint ret(1);
    while (i <= n) {
      if (i & n) ret *= p;
      i = (i << 1);
      p = (p * p) % Mod;
    }
    return ret;
  }
  Modint operator-() const { return (v ? Modint(Mod - v) : Modint(0)); }
  explicit operator int() const { return v; }
  explicit operator long long() const { return v; }
  Modint &operator+=(const Modint &a) {
    v = (v + a.v);
    if (v >= Mod) v -= Mod;
    return *this;
  }
  Modint &operator-=(const Modint &a) {
    v = (v - a.v);
    if (v < 0) v += Mod;
    return *this;
  }
  Modint &operator*=(const Modint &a) {
    v = (v * a.v) % Mod;
    return *this;
  }
  Modint &operator/=(const Modint &a) {
    v = (v * a.mpow(Mod - 2).v) % Mod;
    return *this;
  }
  template <class T>
  Modint &operator+=(const T &a) {
    v = (v + Modint(a).v);
    if (v >= Mod) v -= Mod;
    return *this;
  }
  template <class T>
  Modint &operator-=(const T &a) {
    v = (v - Modint(a).v);
    if (v < 0) v += Mod;
    return *this;
  }
  template <class T>
  Modint &operator*=(const T &a) {
    v = (v * Modint(a).v) % Mod;
    return *this;
  }
  template <class T>
  Modint &operator/=(const T &a) {
    v = (v * Modint(a).mpow(Mod - 2).v) % Mod;
    return *this;
  }
  friend Modint operator+(const Modint &a, const Modint &b) {
    return Modint(a) += b;
  }
  friend Modint operator-(const Modint &a, const Modint &b) {
    return Modint(a) -= b;
  }
  friend Modint operator*(const Modint &a, const Modint &b) {
    return Modint(a) *= b;
  }
  friend Modint operator/(const Modint &a, const Modint &b) {
    return Modint(a) /= b;
  }
  template <class T, class U>
  friend Modint operator+(const T &a, const U &b) {
    return Modint(a) += Modint(b);
  }
  template <class T, class U>
  friend Modint operator-(const T &a, const U &b) {
    return Modint(a) -= Modint(b);
  }
  template <class T, class U>
  friend Modint operator*(const T &a, const U &b) {
    return Modint(a) *= Modint(b);
  }
  template <class T, class U>
  friend Modint operator/(const T &a, const U &b) {
    return Modint(a) /= Modint(b);
  }
};
template <long long M>
ostream &operator<<(ostream &os, const Modint<M> m) {
  return os << m.v;
}
class Solver2 {
 public:
  LL n, m;
  vector<int> like;
  vector<LL> w;
  Solver2(LL n, LL m) : n(n), m(m), like(n), w(n){};
  void solve() {
    LL sumlike = 0;
    LL sumdisl = 0;
    for (int i = 0; i < n; ++i) {
      cin >> like[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
      if (like[i] == 0)
        sumdisl += w[i];
      else
        sumlike += w[i];
    }
    vector<vector<Modint<>>> dpl(51 * m + 1, vector<Modint<>>(51 * m + 1)),
        dpd(51 * m + 1, vector<Modint<>>(51 * m + 1));
    for (int i = 0; i <= 51 * m; ++i) {
      for (int j = 0; j <= 51 * m; ++j) {
        dpl[i][j] = Modint<>(i);
        dpd[i][j] = Modint<>(j);
      }
    }
    vector<Modint<>> rev(10000);
    for (int i = 1; i < rev.size(); ++i) {
      rev[i] = Modint<>(1) / i;
    }
    for (int k = 0; k < m; ++k) {
      for (int i = max((int)sumlike - 100, 1);
           i <= min(sumlike + 100, 51 * m - 1); ++i) {
        for (int j = min(sumdisl + 100, 51 * m);
             j >= max((int)sumdisl - 100, 0); --j) {
          if (i == 0 && j == 0) continue;
          if (i + j >= 2570) continue;
          if (j > 0) {
            dpl[i][j] = (i * dpl[i + 1][j] + j * dpl[i][j - 1]) * rev[i + j];
            dpd[i][j] = (i * dpd[i + 1][j] + j * dpd[i][j - 1]) * rev[i + j];
          } else {
            dpl[i][j] = dpl[i + 1][j];
            dpd[i][j] = dpd[i + 1][j];
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (like[i]) {
        cout << dpl[sumlike][sumdisl] / sumlike * w[i] << endl;
      } else {
        cout << dpd[sumlike][sumdisl] / sumdisl * w[i] << endl;
      }
    }
  }
};
}  // namespace Problem
int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  long long n = 0, m;
  std::cin >> n >> m;
  Problem::Solver2 sol(n, m);
  sol.solve();
  return 0;
}
