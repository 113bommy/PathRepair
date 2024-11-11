#include <bits/stdc++.h>
using namespace std;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
constexpr long long TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (int i = 0; i < (v.size()); i++) {
    if (i) os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}
const long long MOD = 998244353;
const int MX = 80;
long long inv[MX], fact[MX], ifact[MX];
inline void add(long long& x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
long long powmod(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    k /= 2;
  }
  return res;
}
void init_mod() {
  inv[1] = 1;
  for (int i = 2; i < MX; ++i) {
    inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
  }
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < MX; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    ifact[i] = ifact[i - 1] * inv[i] % MOD;
  }
}
long long comb(int n, int r) {
  if (n < 0 || r < 0 || r > n) return 0;
  return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}
const int maxn = 4010;
const int INF = 1e9;
const int maxk = 80;
vector<int> g[maxn];
bool centroid[maxn];
int subtree_size[maxn];
long long way[maxk];
long long dp1[maxn][maxk], dp2[maxn][maxk];
V<int> vs;
int compute_subtree_size(int v, int p) {
  vs.push_back(v);
  int c = 1;
  for (auto w : g[v]) {
    if (w == p || centroid[w]) continue;
    c += compute_subtree_size(w, v);
  }
  return subtree_size[v] = c;
}
pair<int, int> search_centroid(int v, int p, int t) {
  auto res = make_pair(INF, -1);
  int s = 1, m = 0;
  for (auto w : g[v]) {
    if (w == p || centroid[w]) continue;
    res = min(res, search_centroid(w, v, t));
    m = max(m, subtree_size[w]);
    s += subtree_size[w];
  }
  m = max(m, t - s);
  res = min(res, make_pair(m, v));
  return res;
}
void solve_sub(int v) {
  vs.clear();
  compute_subtree_size(v, -1);
  int s = search_centroid(v, -1, subtree_size[v]).second;
  for (int v : vs)
    for (int t = 0; t < (maxk); t++) {
      dp1[v][t] = dp2[v][t] = 0;
    }
  dp1[s][0] = dp2[s][0] = 1;
  for (int i = 0; i < (maxk - 1); i++) {
    for (int v : vs)
      if (dp1[v][i] || dp2[v][i]) {
        for (int w : g[v])
          if (!centroid[w]) {
            add(dp1[w][i + 1], dp1[v][i]);
            if (w != s) {
              add(dp2[w][i + 1], dp2[v][i]);
            }
          }
      }
  }
  for (int v : vs) {
    if (v == s) {
      for (int i = 0; i < (maxk); i++) {
        add(way[i], dp1[s][i]);
      }
    } else {
      for (int i = 0; i < (maxk); i++) {
        for (int j = 0; j < (maxk - i); j++) {
          add(way[i + j], dp1[v][i] * dp2[v][j] % MOD);
        }
      }
    }
  }
  centroid[s] = 1;
  for (int w : g[s]) {
    if (centroid[w]) continue;
    solve_sub(w);
  }
}
void init() {
  for (int i = 0; i < (maxn); i++) g[i].clear();
  memset(centroid, 0, sizeof(centroid));
  memset(way, 0, sizeof(way));
}
long long pway[maxk];
int main() {
  init_mod();
  int n[2], k;
  cin >> n[0] >> n[1] >> k;
  long long ans = 0;
  for (int t = 0; t < (2); t++) {
    init();
    for (int i = 0; i < (n[t] - 1); i++) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    solve_sub(0);
    if (t) {
      for (int i = 0; i <= k; ++i) {
        ans = (ans + way[i] * pway[k - i] % MOD * comb(k, i)) % MOD;
      }
    }
    for (int i = 0; i <= k; ++i) {
      pway[i] = way[i];
    }
  }
  cout << ans << endl;
  return 0;
}
