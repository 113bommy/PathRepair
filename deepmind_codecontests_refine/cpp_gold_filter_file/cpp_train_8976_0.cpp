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
void MACRO_OUT(const T t) {
  std::cout << t;
}
template <typename First, typename... Rest>
void MACRO_OUT(const First first, const Rest... rest) {
  std::cout << first << " ";
  MACRO_OUT(rest...);
}
template <class S, class T, class U>
bool IN(S a, T x, U b) {
  return a <= x && x < b;
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
using i64 = std::int_fast64_t;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<i64, i64>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = (1 << 30) - 1;
constexpr int INFINT_LIM = (1LL << 31) - 1;
constexpr ll INFLL = 1LL << 60;
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);
constexpr double eps = 1e-6;
constexpr i64 MOD = 1000000007;
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
i64 dp[10004][1003];
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  int n, m;
  MACRO_VAR_Scan(n, m);
  ;
  std::vector<int> d(m);
  for (auto& i : d) std::cin >> i;
  ;
  int g, r;
  MACRO_VAR_Scan(g, r);
  ;
  {
    std::set<int> set;
    for (int i = (0); i < (m); ++i) set.insert(d[i]);
    d.resize(0);
    for (auto x : set) d.emplace_back(x);
    m = d.size();
  }
  FILL(dp, (i64)INFLL_LIM);
  dp[0][0] = 0;
  struct P {
    i64 cost;
    int i, j;
    bool operator<(const P& r) const { return cost > r.cost; }
  };
  std::priority_queue<P> pq;
  pq.push(P{0, 0, 0});
  while (!pq.empty()) {
    P now = pq.top();
    pq.pop();
    i64 cost = now.cost;
    int i = now.i, j = now.j;
    if (cost > INFLL) break;
    if (i + 1 == m) {
      MACRO_OUT(dp[i][j]);
      std::cout << "\n";
      ;
      return 0;
    }
    if (i > 0) {
      int dif = d[i] - d[i - 1];
      if (j + dif < g) {
        i64 ncost = dp[i][j] + dif;
        if (dp[i - 1][j + dif] > ncost) {
          dp[i - 1][j + dif] = ncost;
          pq.push(P{ncost, i - 1, j + dif});
        }
      } else if (j + dif == g) {
        i64 ncost = dp[i][j] + dif + r;
        if (dp[i - 1][0] > ncost) {
          dp[i - 1][0] = ncost;
          pq.push(P{ncost, i - 1, 0});
        }
      }
    }
    if (i + 1 < m) {
      int dif = d[i + 1] - d[i];
      if (j + dif < g) {
        i64 ncost = dp[i][j] + dif;
        if (dp[i + 1][j + dif] > ncost) {
          dp[i + 1][j + dif] = ncost;
          pq.push(P{ncost, i + 1, j + dif});
        }
      } else if (j + dif == g) {
        i64 ncost = dp[i][j] + dif + r;
        if (i + 1 == m - 1) ncost -= r;
        if (dp[i + 1][0] > ncost) {
          dp[i + 1][0] = ncost;
          pq.push(P{ncost, i + 1, 0});
        }
      }
    }
  }
  MACRO_OUT(-1);
  std::cout << "\n";
  ;
  return 0;
}
