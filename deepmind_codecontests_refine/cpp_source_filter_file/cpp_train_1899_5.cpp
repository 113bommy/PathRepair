#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  os << "{";
  for (int i = (int)(0); i < (int)(v.size()); ++i)
    os << v[i] << (i == (int)v.size() - 1 ? "" : ", ");
  os << "}";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
  return (os << "(" << p.first << ", " << p.second << ")");
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &m) {
  bool first = true;
  os << "{";
  for (const auto e : m) {
    if (!first) os << ", ";
    os << "{" << e.first << ": " << e.second << "}";
    first = false;
  }
  os << "}";
  return os;
}
template <typename T>
T dup(T x, T y) {
  return (x + y - 1) / y;
};
template <typename A, size_t N, typename T>
inline void arrayFill(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
struct in {
  const size_t n = 0;
  in() = default;
  in(size_t n) : n(n){};
  template <typename T>
  operator T() {
    T ret;
    cin >> ret;
    return ret;
  }
  template <typename T>
  operator vector<T>() {
    assert(n != 0);
    vector<T> ret(n);
    for (T &x : ret) {
      T tmp = in();
      x = tmp;
    }
    return ret;
  }
  template <typename T, typename U>
  operator pair<T, U>() {
    pair<T, U> ret;
    ret.first = in();
    ret.second = in();
    return ret;
  }
};
using ll = int64_t;
using vint = vector<int32_t>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pint = pair<int32_t, int32_t>;
using vpint = vector<pint>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using setint = set<int32_t>;
using setstr = set<string>;
using qint = queue<int32_t>;
using qpint = queue<pint>;
constexpr std::int32_t INF = 1001001001;
constexpr std::int64_t LINF = 1001001001001001001;
void Main() {
  int t = in();
  while (t--) {
    int d = in(), m = in();
    vll v;
    ll tmp = 1;
    while ((tmp << 1) - 1 <= d) {
      v.push_back(tmp);
      tmp <<= 1;
    }
    if (d - tmp + 1 != 0) {
      v.push_back(d - tmp + 1);
    }
    int ans = 1;
    for (int i = (int)(0); i < (int)(v.size()); ++i) {
      ans *= (v[i] + 1) % m;
      ans %= m;
    }
    ans += m - 1;
    ans %= m;
    cout << ans << endl;
  }
}
signed main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}
