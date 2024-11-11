#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <typename T>
struct modular {
  constexpr modular() : val(0) {}
  constexpr modular(const modular<T>& _m) : val(_m.val) {}
  template <typename U>
  constexpr modular(const U& _r = U()) {
    val = -MOD <= _r && _r < MOD ? _r : _r % MOD;
    if (val < 0) {
      val += MOD;
    }
  }
  const T operator()() { return val; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(val);
  }
  modular<T>& operator+=(const modular<T>& _m) {
    if ((val += _m.val) >= MOD) {
      val -= MOD;
    }
    return *this;
  }
  modular<T>& operator-=(const modular<T>& _m) {
    if ((val -= _m.val) < 0) {
      val += MOD;
    }
    return *this;
  }
  modular<T>& operator*=(const modular<T>& _m) {
    val = modular<T>(static_cast<int64_t>(val) * static_cast<int64_t>(_m.val))
              .val;
    return *this;
  }
  modular<T>& operator/=(const modular<T>& _m) {
    T a = _m.val, b = MOD, u = 0, v = 1;
    while (a != 0) {
      T q = b / a;
      b -= q * a;
      swap(a, b);
      u -= q * v;
      swap(u, v);
    }
    return *this *= u;
  }
  modular<T>& operator=(const modular<T>& _m) {
    val = _m.val;
    return *this;
  }
  template <typename U>
  modular<T>& operator+=(const U& _r) {
    return *this += modular<T>(_r);
  }
  template <typename U>
  modular<T>& operator-=(const U& _r) {
    return *this -= modular<T>(_r);
  }
  template <typename U>
  modular<T>& operator*=(const U& _r) {
    return *this *= modular<T>(_r);
  }
  template <typename U>
  modular<T>& operator/=(const U& _r) {
    return *this /= modular<T>(_r);
  }
  template <typename U>
  modular<T>& operator=(const U& _r) {
    val = modular<T>(_r).val;
    return *this;
  }
  modular<T> operator-() { return modular<T>(-val); }
  template <typename U>
  friend bool operator==(const modular<U>&, const modular<U>&);
  friend std::istream& operator>>(std::istream& os, modular<T>& _m) {
    os >> _m.val;
    _m *= 1;
    return os;
  }
  friend std::ostream& operator<<(std::ostream& os, const modular<T>& _m) {
    return os << _m.val;
  }
  template <typename U>
  modular<T> exp(U e) {
    modular<T> res = 1;
    modular<T> b = val;
    if (e < 0) {
      b = 1 / b;
      e *= -1;
    }
    for (; e; e >>= 1) {
      if (e & 1) {
        res *= b;
      }
      b *= b;
    }
    return res;
  }

 private:
  T val;
};
template <typename T>
inline modular<T> operator+(const modular<T>& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) += _rhs;
}
template <typename T, typename U>
inline modular<T> operator+(const modular<T>& _lhs, const U& _rhs) {
  return modular<T>(_lhs) += _rhs;
}
template <typename T, typename U>
inline modular<T> operator+(const U& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) += _rhs;
}
template <typename T>
inline modular<T> operator-(const modular<T>& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) -= _rhs;
}
template <typename T, typename U>
inline modular<T> operator-(const modular<T>& _lhs, const U& _rhs) {
  return modular<T>(_lhs) -= _rhs;
}
template <typename T, typename U>
inline modular<T> operator-(const U& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) -= _rhs;
}
template <typename T>
inline modular<T> operator*(const modular<T>& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) *= _rhs;
}
template <typename T, typename U>
inline modular<T> operator*(const modular<T>& _lhs, const U& _rhs) {
  return modular<T>(_lhs) *= _rhs;
}
template <typename T, typename U>
inline modular<T> operator*(const U& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) *= _rhs;
}
template <typename T>
inline modular<T> operator/(const modular<T>& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) /= _rhs;
}
template <typename T, typename U>
inline modular<T> operator/(const modular<T>& _lhs, const U& _rhs) {
  return modular<T>(_lhs) /= _rhs;
}
template <typename T, typename U>
inline modular<T> operator/(const U& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) /= _rhs;
}
template <typename T>
inline bool operator==(const modular<T>& _lhs, const modular<T>& _rhs) {
  return _lhs.val == _rhs.val;
}
template <typename T, typename U>
inline bool operator==(const modular<T>& _lhs, const U& _rhs) {
  return _lhs == modular<T>(_rhs);
}
template <typename T, typename U>
inline bool operator==(const U& _lhs, const modular<T>& _rhs) {
  return modular<T>(_lhs) == _rhs;
}
template <typename T>
inline bool operator!=(const modular<T>& _lhs, const modular<T>& _rhs) {
  return !(_lhs == _rhs);
}
template <typename T, typename U>
inline bool operator!=(const modular<T>& _lhs, const U& _rhs) {
  return !(_lhs == _rhs);
}
template <typename T, typename U>
inline bool operator!=(const U& _lhs, const modular<T>& _rhs) {
  return !(_lhs == _rhs);
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool x) { return (x ? "T" : "F"); }
string to_string(modular<int> x) { return to_string(int(x)); }
string to_string(const char* s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename V>
string to_string(V v) {
  bool f = true;
  string res = "[";
  for (const auto& x : v) {
    if (!f) res += ", ";
    f = false;
    res += to_string(x);
  }
  res += "]";
  return res;
}
void debug() { cerr << endl; }
template <typename H, typename... T>
void debug(H h, T... t) {
  cerr << " " << to_string(h);
  debug(t...);
}
const int N = 5050;
modular<int> a[N], c[N], res[N << 1];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  c[1] = 1;
  for (int i = 1; i < n; i++) {
    c[i + 1] = c[i] * a[i];
  }
  deque<modular<int> > f = {1}, g = {1};
  for (int i = n; i >= 1; i--) {
    if (i > 1) {
      for (int j = 0; j < g.size(); j++) {
        res[j + 2] -= g[j] * c[i];
      }
    }
    for (auto& x : f) {
      x *= a[i - 1];
    }
    f.push_front(1);
    for (auto& x : g) {
      x *= a[i - 1] * a[i - 1];
    }
    g.push_front(0);
    g.push_front(0);
    for (int j = 0, sz = min(f.size(), g.size()); j < sz; j++) {
      g[j] += 2 * f[j];
    }
    g[0] -= 1;
    2019;
    for (int j = 1; j < g.size(); j++) {
      res[j] += g[j] * c[i - 1];
    }
  }
  modular<int> half = modular<int>(1) / 2;
  for (int j = 1; j <= 2 * n - 2; j++) {
    cout << res[j] * half << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  cout << endl;
}
