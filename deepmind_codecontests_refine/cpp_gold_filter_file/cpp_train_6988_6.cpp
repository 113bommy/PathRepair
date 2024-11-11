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
template <class T>
inline T CHMAX(T& a, const T b) {
  return a = (a < b) ? b : a;
}
template <class T>
inline T CHMIN(T& a, const T b) {
  return a = (a > b) ? b : a;
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
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = 1 << 30;
constexpr int INFINT_LIM = (1LL << 31) - 1;
constexpr ll INFLL = 1LL << 60;
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);
constexpr double EPS = 1e-10;
constexpr int MOD = 998244353;
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
bool g[20][20];
bool h[20][20];
bool dp[16][1 << 16][16];
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  int n, m;
  MACRO_VAR_Scan(n, m);
  ;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (auto& R : a)
    for (auto& w : R) std::cin >> w;
  ;
  auto check = [&](int d) {
    FILL(g, true);
    FILL(h, true);
    FILL(dp, false);
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(n); ++j) {
        for (int k = 0; k < int(m); ++k) {
          if (std::abs(a[i][k] - a[j][k]) < d) {
            g[i][j] = false;
            break;
          }
        }
        for (int k = 0; k < int(m - 1); ++k) {
          if (std::abs(a[i][k] - a[j][k + 1]) < d) {
            h[i][j] = false;
            break;
          }
        }
      }
    for (int root = 0; root < int(n); ++root) {
      dp[root][1 << root][root] = true;
      for (int mask = 0; mask < int(1 << n); ++mask)
        for (int i = 0; i < int(n); ++i) {
          if (!dp[root][mask][i]) continue;
          if (!(mask & 1 << i)) continue;
          for (int j = 0; j < int(n); ++j) {
            if (!g[i][j]) continue;
            if (mask & 1 << j) continue;
            dp[root][mask | 1 << j][j] = true;
          }
        }
      for (int i = 0; i < int(n); ++i)
        if (n == 1 || i != root) {
          if (dp[root][(1 << n) - 1][i] && h[i][root]) return true;
        }
    }
    return false;
  };
  int ng = 1000000009, ok = 0;
  while (ng - ok > 1) {
    int me = (ok + ng) / 2;
    if (check(me))
      ok = me;
    else
      ng = me;
  }
  std::cout << (ok);
  std::cout << "\n";
  ;
  return 0;
}
