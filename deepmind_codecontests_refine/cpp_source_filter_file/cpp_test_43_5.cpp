#include <bits/stdc++.h>
using namespace std;
namespace IO {
char in[1 << 24];
char const *o;
void init_in() {
  o = in;
  in[fread(in, 1, sizeof(in) - 4, stdin)] = 0;
}
int rd() {
  unsigned u = 0, s = 0;
  while (*o && *o <= 32) ++o;
  if (*o == '-')
    s = ~s, ++o;
  else if (*o == '+')
    ++o;
  while (*o >= '0' && *o <= '9') u = (u << 3) + (u << 1) + (*o++ - '0');
  return static_cast<int>((u ^ s) + !!s);
}
char *rdstr(char *s) {
  while (*o && *o <= 32) ++o;
  while (*o > 32) *s++ = *o++;
  *s = '\0';
  return s;
}
}  // namespace IO
template <typename T>
void chkmax(T &a, const T &b) {
  a = max(a, b);
}
template <typename T>
void chkmin(T &a, const T &b) {
  a = min(a, b);
}
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
using IO::rd;
const int N = 2e5 + 5;
vector<pair<int, int> > g[N];
int e[N], a[N], b[N], c[N], t[N];
int n;
int f[18][N], dep[N], fg[20][N];
void dfs(int u, int fa) {
  f[0][u] = fa;
  for (auto [v, w] : g[u]) {
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    fg[0][v] = w;
    dfs(v, u);
  }
}
inline void lca_init() {
  dfs(1, 0);
  for (int i = 1; i < 18; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = f[i - 1][f[i - 1][j]];
      fg[i][j] = max(fg[i - 1][j], fg[i - 1][f[i - 1][j]]);
    }
  }
}
int path(int u, int v) {
  if (u == v) return 0;
  int ret = 0;
  if (dep[u] < dep[v]) swap(u, v);
  int x = dep[u] - dep[v];
  for (int i = 17; i >= 0; --i) {
    if ((x >> i) & 1) chkmax(ret, fg[i][u]), u = f[i][u];
  }
  if (u == v) return ret;
  for (int i = 17; i >= 0; --i) {
    if (f[i][u] != f[i][v]) {
      chkmax(ret, max(fg[i][u], fg[i][v]));
      u = f[i][u];
      v = f[i][v];
    }
  }
  chkmax(ret, max(fg[0][u], fg[0][v]));
  return ret;
}
struct DS {
  int f[N], sz[N];
  vector<int> mx[N];
  int mxe[N], mxc[N];
  inline void init() {
    iota(f + 1, f + n + 1, 1);
    for (int i = 1; i < n + 1; ++i)
      mx[i].push_back(i), mxe[i] = e[i], sz[i] = 1;
  }
  int get(int x) { return (x == f[x]) ? x : (f[x] = get(f[x])); }
  void merge(int id) {
    int u = get(a[id]), v = get(b[id]);
    if (sz[u] < sz[v]) swap(u, v);
    if (mxe[u] > mxe[v]) {
    } else if (mxe[u] < mxe[v]) {
      mxe[u] = mxe[v];
      mxc[u] = mxc[v];
      mx[u].swap(mx[v]);
    } else {
      for (auto t : mx[v]) {
        chkmax(mxc[u], path(t, *mx[u].begin()));
        mx[u].push_back(t);
      }
    }
    sz[u] += sz[v];
    f[v] = u;
    vector<int> stash;
    mx[v].swap(stash);
  }
  pair<int, int> qry(int x) {
    int ft = get(x);
    return {mxe[ft], max(mxc[x], path(x, *mx[ft].begin()))};
  }
} D;
int ord[N], ord2[N];
int v[N], x[N];
pair<int, int> ans[N];
void solve() {
  n = rd();
  int q = rd();
  for (int i = 1; i < n + 1; ++i) e[i] = rd();
  for (int i = 1; i < n; ++i) {
    a[i] = rd(), b[i] = rd(), c[i] = rd(), t[i] = rd();
    g[a[i]].emplace_back(b[i], t[i]);
    g[b[i]].emplace_back(a[i], t[i]);
  }
  lca_init();
  D.init();
  iota(ord + 1, ord + n, 1);
  sort(ord + 1, ord + n, [](int a, int b) { return c[a] > c[b]; });
  for (int i = 0; i < q; ++i) v[i] = rd(), x[i] = rd();
  iota(ord2, ord2 + q, 0);
  sort(ord2, ord2 + q, [](int a, int b) { return v[a] > v[b]; });
  for (int l = 1, i = 0; i < q; ++i) {
    while (l < n && c[ord[l]] >= v[ord2[i]]) D.merge(ord[l++]);
    ans[ord2[i]] = D.qry(x[ord2[i]]);
  }
  for (int i = 0; i < q; ++i)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
}
int main() {
  IO::init_in();
  solve();
  return 0;
}
