#include <bits/stdc++.h>
template <typename Y>
inline bool updmin(Y &a, Y b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline bool updmax(Y &a, Y b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline Y abs(Y a) {
  if (a < 0) a = -a;
  return a;
}
template <typename Y>
inline Y sqr(Y a) {
  return a * a;
}
int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}
inline void FileIO() {
  freopen(
      ""
      ".in",
      "r", stdin);
  freopen(
      ""
      ".out",
      "w", stdout);
}
const int maxn = 800010;
std::vector<std::pair<int, long long> > G[maxn];
int n, m, fa[maxn];
long long a[maxn], d[maxn], dk[maxn], df[maxn];
int dep[maxn], dfn[maxn], st[maxn][19], dfc = 0, lg[maxn];
int lca(int a, int b) {
  a = dfn[a];
  b = dfn[b];
  if (a > b) {
    std::swap(a, b);
  }
  int L = lg[b - a], u = st[a][L], v = st[b - (1 << L) + 1][L];
  return dep[u] < dep[v] ? u : v;
}
void up(int p) {
  d[p] = a[p];
  st[++dfc][0] = p;
  dfn[p] = dfc;
  dep[p] = dep[fa[p]] + 1;
  for (auto t : G[p]) {
    if (t.first == fa[p]) continue;
    fa[t.first] = p;
    up(t.first);
    dk[t.first] = std::max(0LL, d[t.first] - 2 * t.second);
    d[p] += dk[t.first];
    st[++dfc][0] = p;
  }
}
void down(int p) {
  for (auto t : G[p]) {
    if (t.first == fa[p]) continue;
    df[t.first] = std::max(0LL, d[p] - dk[t.first] - 2 * t.second);
    d[t.first] += df[t.first];
    down(t.first);
  }
}
long long ans[maxn];
std::vector<std::pair<int, int> > Q[maxn];
long long tr[maxn];
inline void add(int p, long long v) {
  if (!p) return;
  for (; p <= n; p += p & -p) {
    tr[p] += v;
  }
}
inline long long ask(int p) {
  long long r = 0;
  for (; p; p -= p & -p) {
    r += tr[p];
  }
  return r;
}
inline long long ask(int l, int r) { return ask(r) - ask(l - 1); }
void dfs(int p, long long ev) {
  add(dep[p] - 1, -ev - dk[p]);
  add(dep[p], d[p] - df[p]);
  for (auto q : Q[p]) {
    ans[q.second] += ask(dep[q.first], dep[p]);
  }
  for (auto t : G[p]) {
    if (t.first == fa[p]) continue;
    dfs(t.first, t.second);
  }
  add(dep[p] - 1, ev + dk[p]);
  add(dep[p], df[p] - d[p]);
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    long long z = read();
    G[x].push_back(std::make_pair(y, z));
    G[y].push_back(std::make_pair(x, z));
  }
  up(1);
  down(1);
  lg[1] = 0;
  for (int i = 2; i <= dfc; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int k = 1; k <= 18; k++) {
    for (int i = 1; i + (1 << k) - 1 <= dfc; i++) {
      int u = st[i][k - 1], v = st[i + (1 << (k - 1))][k - 1];
      st[i][k] = dep[u] < dep[v] ? u : v;
    }
  }
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    if (u == v) {
      ans[i] = d[u];
      continue;
    }
    int l = lca(u, v);
    if (l != u && l != v) {
      ans[i] += 2 * df[l] - d[l];
    } else {
      ans[i] += df[l];
    }
    if (l != u) {
      Q[u].push_back(std::make_pair(l, i));
    }
    if (l != v) {
      Q[v].push_back(std::make_pair(l, i));
    }
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
