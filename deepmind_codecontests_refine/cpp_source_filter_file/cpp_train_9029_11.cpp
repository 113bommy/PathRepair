#include <bits/stdc++.h>
using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::string;
using std::stringstream;
using std::vector;
class MyTimer {
 public:
  void reset() {}
  void report() {}
} myTimer;
template <typename A, typename B>
std::ostream &operator<<(std::ostream &cout, const pair<A, B> &x) {
  return cout << "(" << x.first << ", " << x.second << ")";
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) {
  return a > b ? a = b, true : false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) {
  return a < b ? a = b, true : false;
}
const int maxN = 4000 + 5;
const int maxK = 75 + 5;
const unsigned P = 998244353;
unsigned long long qpow(unsigned long long a, unsigned long long b) {
  unsigned long long r = 1;
  while (b) {
    if (b & 1) (r *= a) %= P;
    (a *= a) %= P;
    b >>= 1;
  }
  return r;
}
unsigned long long fac[maxN], ifac[maxN];
unsigned long long choose(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fac[n] * ifac[k] % P * ifac[n - k] % P;
}
int m;
void inc(unsigned &x, unsigned y) { (x += y) >= P ? x -= P : x; }
typedef unsigned Array[maxN];
Array buc1[maxN], buc2[maxN];
Array *x = buc1, *y = buc2;
struct Tree {
  int n;
  vector<int> G[maxN];
  void read() {
    for (int i = 1; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
  }
  unsigned f[maxK][maxN];
  void calc() {
    memset(x, 0, sizeof(buc1));
    memset(y, 0, sizeof(buc1));
    for (int u = 1; u <= n; ++u) x[u][u] = 1;
    for (int i = 0; i <= m; ++i) {
      for (int u = 1; u <= n; ++u) f[i][u] = x[u][u];
      memset(y, 0, sizeof(buc1));
      for (int u = 1; u <= n; ++u) {
        for (int v : G[u]) {
          for (int t = 1; t <= n; ++t) inc(y[u][t], x[v][t]);
        }
      }
      std::swap(x, y);
    }
  }
} X, Y;
unsigned g[maxK];
int main() {
  std::ios::sync_with_stdio(false);
  cin >> X.n >> Y.n >> m;
  X.read();
  Y.read();
  X.calc();
  Y.calc();
  for (int i = 0; i <= m; ++i)
    for (int u = 1; u <= Y.n; ++u) inc(g[i], Y.f[i][u]);
  fac[0] = 1;
  for (int i = 1; i < maxN; ++i) fac[i] = fac[i - 1] * i % P;
  ifac[maxN - 1] = qpow(fac[maxN - 1], P - 2);
  for (int i = maxN - 2; i >= 0; --i) ifac[i] = ifac[i + 1] * (i + 1) % P;
  unsigned ans = 0;
  for (int i = 0; i <= m; ++i)
    for (int u = 1; u <= X.n; ++u)
      inc(ans, (unsigned long long)X.f[i][u] * g[m - i] % P * choose(m, i));
  cout << ans << endl;
  return 0;
}
