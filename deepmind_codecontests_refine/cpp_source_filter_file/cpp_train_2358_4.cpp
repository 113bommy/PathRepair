#include <bits/stdc++.h>
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
template <typename T>
inline T CHMAX(T& a, const T b) {
  return a = (a < b) ? b : a;
}
template <typename T>
inline T CHMIN(T& a, const T b) {
  return a = (a > b) ? b : a;
}
void CHECKTIME(std::function<void()> f) {
  auto start = std::chrono::system_clock::now();
  f();
  auto end = std::chrono::system_clock::now();
  auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start))
                 .count();
  std::cerr << "[Time:" << res << "ns  (" << res / (1.0e9) << "s)]\n";
}
template <class T>
std::vector<std::vector<T>> VV(int n, int m, T init = T()) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, init));
}
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
constexpr ll INFINT = 1 << 30;
constexpr ll INFINT_LIM = (1LL << 31) - 1;
constexpr ll INFLL = 1LL << 60;
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);
constexpr double EPS = 1e-9;
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
std::vector<ll> w({0});
std::vector<std::vector<ll>> P(1, std::vector<ll>(20, -1));
std::vector<std::vector<ll>> S(1, std::vector<ll>(20, 0));
void add(ll R, ll W) {
  w.emplace_back(W);
  std::vector<ll> par(20, -1);
  if (w[R] >= W)
    par[0] = R;
  else {
    ll now = R;
    for (ll i = ll(20) - 1; i >= 0; --i) {
      if (P[now][i] == -1) continue;
      if (w[P[now][i]] < R) now = P[now][i];
    }
    par[0] = P[now][0];
  }
  for (ll i = (1); i < (20); ++i) {
    if (par[i - 1] == -1) break;
    par[i] = P[par[i - 1]][i - 1];
  }
  std::vector<ll> sum;
  if (par[0] == -1) {
    sum.resize(20, 0);
  } else {
    sum = S[par[0]];
    for (ll i = 0; i < ll(20); ++i) {
      sum[i] += w[par[0]];
      if (par[i] == -1) continue;
      if (P[par[i]][0] == -1) continue;
      sum[i] -= w[P[par[i]][0]];
    }
  }
  P.emplace_back(par);
  S.emplace_back(sum);
}
ll query(ll R, ll X) {
  if (w[R] > X) return 0;
  X -= w[R];
  ll now = R;
  ll res = 1;
  for (ll i = ll(20) - 1; i >= 0; --i) {
    if (P[now][i] == -1) continue;
    if (S[now][i] <= X) {
      X -= S[now][i];
      now = P[now][i];
      res += 1 << i;
    }
  }
  return res;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  ll Q;
  MACRO_VAR_Scan(Q);
  ;
  ll last = 0;
  for (ll _ = 0; _ < ll(Q); ++_) {
    ll t, p, q;
    MACRO_VAR_Scan(t, p, q);
    ;
    p ^= last;
    q ^= last;
    --p;
    if (t == 1) {
      add(p, q);
    } else {
      std::cout << (last = query(p, q));
      std::cout << "\n";
      ;
    }
  }
  return 0;
}
