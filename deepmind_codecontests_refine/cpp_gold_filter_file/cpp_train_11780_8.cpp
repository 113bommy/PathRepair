#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <typename T>
void MACRO_VAR_Scan(T& t) {
  std::cin >> t;
}
template <typename First, typename... Rest>
void MACRO_VAR_Scan(First& first, Rest&... rest) {
  std::cin >> first;
  MACRO_VAR_Scan(rest...);
}
template <typename T>
void MACRO_VEC_ROW_Init(int n, T& t) {
  t.resize(n);
}
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Init(int n, First& first, Rest&... rest) {
  first.resize(n);
  MACRO_VEC_ROW_Init(n, rest...);
}
template <typename T>
void MACRO_VEC_ROW_Scan(int p, T& t) {
  std::cin >> t[p];
}
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Scan(int p, First& first, Rest&... rest) {
  std::cin >> first[p];
  MACRO_VEC_ROW_Scan(p, rest...);
}
template <class T>
inline T CHMAX(T& a, const T b) {
  return a = (a < b) ? b : a;
}
template <class T>
inline T CHMIN(T& a, const T b) {
  return a = (a > b) ? b : a;
}
template <class T>
using V = std::vector<T>;
template <class T>
using VV = V<V<T>>;
template <typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<ll, ll>;
using PAIRLL = std::pair<ll, ll>;
constexpr ll INFINT = (1 << 30) - 1;
constexpr ll INFINT_LIM = (1LL << 31) - 1;
constexpr ll INFLL = 1LL << 60;
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);
constexpr double EPS = 1e-6;
constexpr ll MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;
template <class T, size_t N>
void FILL(T (&a)[N], const T& val) {
  for (auto& x : a) x = val;
}
template <class ARY, size_t N, size_t M, class T>
void FILL(ARY (&a)[N][M], const T& val) {
  for (auto& b : a) FILL(b, val);
}
template <class T>
void FILL(std::vector<T>& a, const T& val) {
  for (auto& x : a) x = val;
}
template <class ARY, class T>
void FILL(std::vector<std::vector<ARY>>& a, const T& val) {
  for (auto& b : a) FILL(b, val);
}
namespace Monoid {
template <class T>
class sum {
 public:
  using value_type = T;
  inline static T operation(const T& a, const T& b) { return a + b; }
  inline static T identity() { return T(0); }
};
template <class T>
class max {
 public:
  using value_type = T;
  inline static T operation(const T& a, const T& b) { return (a < b) ? b : a; }
  inline static T identity() { return std::numeric_limits<T>::lowest(); }
};
template <class T>
class min {
 public:
  using value_type = T;
  inline static T operation(const T& a, const T& b) { return (a < b) ? a : b; }
  inline static T identity() { return std::numeric_limits<T>::max(); }
};
class MONOID {
 public:
  struct S {
    ll x;
  };
  using value_type = S;
  inline static S operation(const S& l, const S& r) { return S{l.x + r.x}; }
  inline static S identity() { return S{0}; }
};
}  // namespace Monoid
template <class Monoid>
class SegmentTree {
 private:
  using T = typename Monoid::value_type;
  ll ARY_SIZE;
  std::vector<T> ary;
  void init(ll n) {
    while (ARY_SIZE < n) ARY_SIZE <<= 1;
    ary.resize(ARY_SIZE << 1, Monoid::identity());
  }

 public:
  SegmentTree(ll n) : ARY_SIZE(1) { init(n); }
  SegmentTree(std::vector<T>& a) : ARY_SIZE(1) {
    init(a.size());
    std::copy(a.begin(), a.end(), ary.begin() + ARY_SIZE);
    for (ll i = ARY_SIZE - 1; i >= 1; --i) {
      ary[i] = Monoid::operation(ary[i << 1], ary[(i << 1) + 1]);
    }
  }
  inline void update(ll i, T val) {
    i += ARY_SIZE;
    ary[i] = val;
    while (i > 1) {
      i >>= 1;
      ary[i] = Monoid::operation(ary[i << 1], ary[(i << 1) + 1]);
    }
  }
  inline void add(ll i, T val) { update(i, ary[i + ARY_SIZE] + val); }
  inline T query(ll l, ll r) {
    if (l >= r) return Monoid::identity();
    T vl = Monoid::identity(), vr = Monoid::identity();
    for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
      if (l & 1) vl = Monoid::operation(vl, ary[l++]);
      if (r & 1) vr = Monoid::operation(ary[--r], vr);
    }
    return Monoid::operation(vl, vr);
  }
  T operator[](ll i) { return ary[i + ARY_SIZE]; }
  void debugShow() {
    for (ll i = ARY_SIZE; i < ARY_SIZE << 1; ++i) std::cerr << ary[i] << " ";
    std::cerr << "\n";
  }
};
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  ll n, m, q;
  MACRO_VAR_Scan(n, m, q);
  ;
  std::vector<ll> p(n);
  for (auto& i : p) std::cin >> i;
  ;
  std::vector<ll> a(m);
  for (auto& i : a) std::cin >> i;
  ;
  std::vector<ll> l, r;
  MACRO_VEC_ROW_Init(q, l, r);
  for (ll w_ = 0; w_ < q; ++w_) {
    MACRO_VEC_ROW_Scan(w_, l, r);
  };
  for (ll i = 0; i < ll(n); ++i) --p[i];
  for (ll i = 0; i < ll(m); ++i) --a[i];
  {
    V<ll> inv(n);
    for (ll i = 0; i < ll(n); ++i) inv[p[i]] = i;
    for (ll i = 0; i < ll(m); ++i) {
      a[i] = inv[a[i]];
    }
  }
  VV<ll> pos(n);
  for (ll i = 0; i < ll(m); ++i) {
    pos[a[i]].emplace_back(i);
  }
  const ll L = 18;
  VV<ll> next(L + 1, V<ll>(m, INFINT));
  for (ll i = 0; i < ll(m); ++i) {
    ll ne = a[i] + 1;
    if (ne == n) ne = 0;
    auto it = std::upper_bound((pos[ne]).begin(), (pos[ne]).end(), i);
    ll p = INFINT;
    if (it != pos[ne].end()) p = *it;
    next[0][i] = p;
  }
  for (ll k = 0; k < ll(L); ++k) {
    for (ll i = 0; i < ll(m); ++i) {
      if (next[k][i] == INFINT)
        next[k + 1][i] = INFINT;
      else
        next[k + 1][i] = next[k][next[k][i]];
    }
  }
  V<ll> b(m);
  for (ll i = 0; i < ll(m); ++i) {
    ll p = i;
    for (ll k = ll(L) - 1; k >= 0; --k) {
      if (p == INFINT) break;
      if ((n - 1) & 1 << k) p = next[k][p];
    }
    b[i] = p;
  }
  SegmentTree<Monoid::min<ll>> st(b);
  for (ll i = 0; i < ll(q); ++i) {
    --l[i];
    ll mi = st.query(l[i], r[i]);
    bool f = mi < r[i];
    std::cout << (f ? 1 : 0);
    ;
  }
  std::cout << "\n";
  ;
  return 0;
}
