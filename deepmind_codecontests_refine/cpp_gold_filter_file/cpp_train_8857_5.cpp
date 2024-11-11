#include <bits/stdc++.h>
using namespace std;
using LL = long long;
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }
  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod()) value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0) value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) *
                                         rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }
  friend const Type& abs(const Modular& x) { return x.value; }
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};
template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}
template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}
template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
using ModType = int;
struct VarMod {
  static ModType value;
};
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
const int MAXN = 100010;
struct Node {
  int l, r, k;
  int id;
};
int v[MAXN];
vector<Node> x[110];
LL cnt[MAXN];
Mint ans[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  md = 998244353;
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    --v[i];
  }
  vector<Node> raw(q);
  map<int, int> h;
  for (int i = 0; i < q; ++i) {
    cin >> raw[i].l >> raw[i].r >> raw[i].k;
    raw[i].id = i;
    --raw[i].l;
    --raw[i].r;
    h[raw[i].k] = 0;
  }
  int nn = 0;
  for (auto& [a, b] : h) b = nn++;
  for (int i = 0; i < q; ++i) {
    x[h[raw[i].k]].push_back(raw[i]);
  }
  for (int g = 0; g < nn; ++g) {
    int Q = x[g].size();
    int S = n / sqrt(Q);
    if (S == 0) S = 1;
    sort(x[g].begin(), x[g].end(), [S](const Node& a, const Node& b) {
      if (a.l / S != b.l / S) return a.l / S < b.l / S;
      return a.r < b.r;
    });
    for (int i = 0; i < m; ++i) cnt[i] = x[g][0].k;
    for (int i = 0; i < n; ++i) ++cnt[v[i]];
    LL sum = 1LL * x[g][0].k * m + n;
    vector<Mint> sumf{1};
    for (int i = n - 1; i >= 0; --i) sumf.push_back(sumf.back() * (sum - i));
    for (int i = 0; i < x[g].size(); ++i) {
      if (x[g][i].l / S == x[g][i].r / S) {
        Mint pb = 1;
        for (int j = x[g][i].l; j <= x[g][i].r; ++j) {
          pb *= cnt[v[j]];
          --cnt[v[j]];
        }
        ans[x[g][i].id] = pb * sumf[n - x[g][i].r + x[g][i].l - 1];
        x[g][i].id = -1;
        for (int j = x[g][i].l; j <= x[g][i].r; ++j) {
          ++cnt[v[j]];
        }
      }
    }
    Mint p = 1;
    int l = 0, r = 0;
    int preb = -1, prer = -1;
    Mint prep = 1;
    for (int i = 0; i < x[g].size(); ++i) {
      if (x[g][i].id == -1) continue;
      int lr = min(x[g][i].l / S * S + S, n);
      if (x[g][i].l / S != preb) {
        while (l < lr) ++cnt[v[l++]];
        while (r < lr) --cnt[v[r++]];
        while (r > lr) ++cnt[v[--r]];
        p = 1;
        preb = x[g][i].l / S;
      } else {
        while (l < lr) ++cnt[v[l++]];
        p = prep;
        r = prer;
      }
      while (r <= x[g][i].r) {
        p *= cnt[v[r]];
        --cnt[v[r++]];
      }
      prep = p;
      prer = r;
      while (l > x[g][i].l) {
        p *= cnt[v[--l]];
        --cnt[v[l]];
      }
      ans[x[g][i].id] = p * sumf[n - x[g][i].r + x[g][i].l - 1];
    }
  }
  for (int i = 0; i < q; ++i) cout << ans[i] << "\n";
  return 0;
}
