#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;
const long long INF_LL = 0x3f3f3f3f3f3f3f3fLL;
inline int getplc(int x, int y) { return (x >> y) & 1; }
template <typename T>
T square(T x) {
  return x * x;
}
long long qpow(long long a, long long b = MOD - 2, long long _MOD = MOD) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % _MOD) {
    if (b & 1) res = res * a % _MOD;
  }
  return res;
}
template <typename T>
T Smax(T x) {
  return x;
}
template <typename T, typename... Args>
T Smax(T a, Args... args) {
  return max(a, Smax(args...));
}
template <typename T>
T Smin(T x) {
  return x;
}
template <typename T, typename... Args>
T Smin(T a, Args... args) {
  return min(a, Smin(args...));
}
template <typename T>
void errl(istream_iterator<string> it) {}
template <typename T, typename... Args>
void errl(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  errl(++it, args...);
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << "=" << a << " # ";
  err(++it, args...);
}
void Solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  Solve();
  return 0;
}
class Union_set {
 public:
  int fa[N], siz[N], n;
  void init(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  }
  int find(int x) { return fa[x] != x ? fa[x] = find(fa[x]) : x; }
  void Union(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (fx > fy) swap(fx, fy);
    fa[fx] = fy;
    siz[fy] += siz[fx];
  }
} us;
int n, m, K, key[N], W[N], C[N], nc[N];
struct Edge {
  int u, v, w;
} e[N];
vector<pair<int, int> > g[N];
stack<int> sta;
bool insta[N];
int low[N], dfn[N], col[N], ind, cnt;
void tarjan(int x, int _fa) {
  low[x] = dfn[x] = ++ind;
  sta.push(x);
  insta[x] = 1;
  for (auto v : g[x])
    if (v.first != _fa) {
      if (!dfn[v.first])
        tarjan(v.first, x), low[x] = min(low[x], low[v.first]);
      else if (insta[v.first])
        low[x] = min(low[x], dfn[v.first]);
    }
  if (low[x] == dfn[x]) {
    int v;
    ++cnt;
    do {
      v = sta.top();
      sta.pop();
      insta[v] = 0;
      col[v] = cnt;
    } while (dfn[v] != low[v]);
  }
}
long long f[N], fg[N];
int son[N];
void dfs(int x, int _fa) {
  f[x] = C[x];
  son[x] |= key[x];
  for (auto &v : g[x])
    if (v.first != _fa) {
      dfs(v.first, x);
      son[x] |= son[v.first];
      if (!son[v.first]) v.second = 0;
      f[x] += max(f[v.first] - v.second, 0LL);
    }
}
void dfs2(int x, int _fa, int fr) {
  fg[x] = f[x] + fr;
  for (auto v : g[x])
    if (v.first != _fa) {
      dfs2(v.first, x,
           max(0LL, fg[x] - max(f[v.first] - v.second, 0LL) - v.second));
    }
}
void Solve() {
  cin >> n >> m >> K;
  us.init(n);
  int rt = -1;
  for (int i = 1; i <= K; i++) {
    int x;
    cin >> x;
    rt = x;
    key[x] = 1;
  }
  for (int i = 1; i <= n; i++) cin >> C[i];
  for (int i = 1; i <= m; i++) cin >> W[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[i] = (Edge){u, v, W[i]};
    g[u].emplace_back(v, 0), g[v].emplace_back(u, 0);
  }
  tarjan(1, 1);
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v, &w = e[i].w;
    if (col[u] == col[v]) {
      w = 0;
    }
    if (us.find(u) != us.find(v)) {
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
      us.Union(u, v);
    }
  }
  dfs(rt, rt);
  dfs2(rt, rt, 0);
  for (int i = 1; i <= n; i++) {
    cout << fg[i] << " ";
  }
}
