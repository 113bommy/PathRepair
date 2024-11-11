#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MOD2 = 1007681537;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
const int maxn = 3e5 + 5;
const int logn = 20;
int n;
vector<int> adj[maxn];
int lev[maxn];
int p[logn][maxn];
int tin[maxn];
int tou[maxn];
int tms;
void dfs(int u) {
  tin[u] = tms++;
  for (int i = (1); i < (logn); i++) p[i][u] = p[i - 1][p[i - 1][u]];
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i];
    lev[v] = lev[u] + 1;
    p[0][v] = u;
    dfs(v);
  }
  tou[u] = tms - 1;
}
int lca(int u, int v) {
  if (lev[u] < lev[v]) swap(u, v);
  for (int i = (logn)-1; i >= (0); i--) {
    if (lev[p[i][u]] >= lev[v]) {
      u = p[i][u];
    }
  }
  if (u == v) return u;
  for (int i = (logn)-1; i >= (0); i--) {
    if (p[i][u] != p[i][v]) {
      u = p[i][u];
      v = p[i][v];
    }
  }
  return p[0][u];
}
int dist(int u, int v) {
  int a = lca(u, v);
  return lev[u] + lev[v] - lev[a] - lev[a];
}
int jump(int u, int d) {
  for (int i = (logn)-1; i >= (0); i--) {
    if (d >= (1 << i)) {
      u = p[i][u];
      d -= 1 << i;
    }
  }
  return u;
}
int st[maxn << 2];
int lz[maxn << 2];
void pushdown(int p, int L, int R) {
  if (~lz[p]) {
    st[p] = lz[p];
    if (L < R) {
      lz[p << 1] = lz[p];
      lz[p << 1 | 1] = lz[p];
    }
    lz[p] = -1;
  }
}
void upd(int p, int l, int r, int L, int R, int val) {
  pushdown(p, L, R);
  if (l > R || r < L) return;
  if (l <= L && r >= R) {
    lz[p] = val;
    pushdown(p, L, R);
    return;
  }
  upd(p << 1, l, r, L, L + R >> 1, val);
  upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
  st[p] = st[p << 1] + st[p << 1 | 1];
}
void solve() {
  cin >> n;
  for (int i = (1); i < (n + 1); i++) {
    int x;
    cin >> x;
    x--;
    adj[x].push_back(i);
  }
  dfs(0);
  memset(lz, -1, sizeof(lz));
  upd(1, 0, 0, 0, n, 1);
  int x = 0, y = 0;
  for (int u = (1); u < (n + 1); u++) {
    int cur = dist(x, y);
    pair<int, pair<int, int> > best = make_pair(-INF, make_pair(-INF, -INF));
    chkmax(best, make_pair(dist(u, x), make_pair(u, x)));
    chkmax(best, make_pair(dist(u, y), make_pair(u, y)));
    int d = best.first;
    if (d == cur) {
      upd(1, tin[u], tin[u], 0, n, 1);
    } else if (d > cur) {
      x = best.second.first;
      y = best.second.second;
      if (lev[x] == lev[y]) {
        int w = jump(y, (d >> 1) - 1);
        upd(1, 0, tin[w] - 1, 0, n, 0);
        upd(1, tou[w] + 1, n, 0, n, 0);
      } else if (lev[x] > lev[y]) {
        int w = jump(x, d >> 1);
        upd(1, tin[w], tou[w], 0, n, 0);
      } else {
        int w = jump(y, d - (d >> 1) - 1);
        upd(1, 0, tin[w] - 1, 0, n, 0);
        upd(1, tou[w] + 1, n, 0, n, 0);
      }
      upd(1, tin[u], tin[u], 0, n, 1);
    }
    cout << st[1] << "\n";
  }
}
int main() {
  int JUDGE_ONLINE = 1;
  if (fopen("in.txt", "r")) {
    JUDGE_ONLINE = 0;
    assert(freopen("in.txt", "r", stdin));
  } else {
    ios_base::sync_with_stdio(0), cin.tie(0);
  }
  solve();
  if (!JUDGE_ONLINE) {
  }
  return 0;
}
