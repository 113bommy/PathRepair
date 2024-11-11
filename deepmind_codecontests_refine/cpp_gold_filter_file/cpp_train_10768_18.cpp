#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return a > val ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
const int oo = (int)1e9;
struct Dinic {
  int n, s, t, E, adj[1000010], next[1000010], last[100010], run[100010],
      level[100010], que[100010];
  int flow[1000010], cap[1000010];
  void init(int _n, int _s, int _t) {
    n = _n;
    s = _s;
    t = _t;
    E = 0;
    fill_n(last, n + 1, -1);
  }
  void add(int u, int v, int c1, int c2) {
    adj[E] = v;
    flow[E] = 0;
    cap[E] = c1;
    next[E] = last[u];
    last[u] = E++;
    adj[E] = u;
    flow[E] = 0;
    cap[E] = c2;
    next[E] = last[v];
    last[v] = E++;
  }
  int bfs() {
    fill_n(level, n + 1, -1);
    level[s] = 0;
    int qsize = 0;
    que[qsize++] = s;
    for (int i = 0; i < qsize; i++) {
      for (int u = que[i], e = last[u]; ~e; e = next[e]) {
        int v = adj[e];
        if (flow[e] < cap[e] && !~level[v]) {
          level[v] = level[u] + 1;
          que[qsize++] = v;
        }
      }
    }
    return level[t] != -1;
  }
  int dfs(int u, int bot) {
    if (u == t) return bot;
    for (int& e = run[u]; ~e; e = next[e]) {
      int v = adj[e];
      int delta = 0;
      if (level[v] == level[u] + 1 && flow[e] < cap[e] &&
          (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
        flow[e] += delta;
        flow[e ^ 1] -= delta;
        return delta;
      }
    }
    return 0;
  }
  int maxflow() {
    int total = 0;
    while (bfs()) {
      for (int i = 0; i <= n; i++) run[i] = last[i];
      for (int delta = dfs(s, oo); delta > 0; delta = dfs(s, oo))
        total += delta;
    }
    return total;
  }
} dinic;
const int maxn = 60;
int n, m;
int a[maxn];
int b[maxn];
int c[maxn];
int l[maxn];
int r[maxn];
int id[maxn][210];
int f(int i, int x) { return a[i] * x * x + b[i] * x + c[i]; }
void solve() {
  cin >> n >> m;
  int tot = 0;
  for (int i = (0); i < (n); i++) cin >> a[i] >> b[i] >> c[i];
  int dmax = -INF;
  for (int i = (0); i < (n); i++) {
    cin >> l[i] >> r[i];
    for (int j = (l[i] - 1); j < (r[i] + 1); j++) {
      id[i][j - l[i] + 1] = tot++;
      chkmax(dmax, f(i, j));
    }
  }
  int s = tot++, t = tot++;
  dinic.init(tot, s, t);
  for (int i = (0); i < (n); i++) {
    dinic.add(s, id[i][0], INF, 0);
    dinic.add(id[i][r[i] - l[i] + 1], t, INF, 0);
    for (int j = (l[i] - 1); j < (r[i]); j++) {
      dinic.add(id[i][j - l[i] + 1], id[i][j - l[i] + 2], dmax - f(i, j + 1),
                0);
    }
  }
  while (m--) {
    int u, v, d;
    cin >> u >> v >> d;
    u--;
    v--;
    for (int i = (l[u] - 1); i < (r[u] + 1); i++) {
      if (i - d >= l[v] - 1 && i - d <= r[v]) {
        dinic.add(id[u][i - l[u] + 1], id[v][i - d - l[v] + 1], INF, 0);
      }
    }
  }
  cout << dmax * n - dinic.maxflow() << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
