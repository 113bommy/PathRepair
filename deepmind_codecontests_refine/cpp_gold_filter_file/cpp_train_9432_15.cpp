#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
int dfs_clock, n, u, v, hed[maxn], s[maxn], ed, tp, p, dfn[maxn];
set<pair<long long, int>, greater<pair<long long, int> > > a, b;
long long d[maxn], sum[maxn], w, max_dep, t;
bool vis[maxn];
struct edge {
  int to, nex;
  long long val;
  edge(int _ = 0, int __ = 0, long long ___ = 0) : to(_), nex(__), val(___) {}
} e[maxn << 1];
inline void add_edge(int u, int v, long long w) {
  e[++ed] = edge(v, hed[u], w);
  hed[u] = ed;
}
bool get_cir(int u, int fa) {
  if (dfn[u]) {
    if (vis[u]) return 0;
    s[++tp] = u;
    vis[u] = 1;
    return 1;
  }
  dfn[u] = ++dfs_clock;
  bool fxk = 0;
  for (int i = hed[u], v = e[i].to; i; i = e[i].nex, v = e[i].to)
    if (v != fa) {
      if (get_cir(v, u)) {
        if (!vis[u])
          vis[u] = fxk = 1, s[++tp] = u, sum[tp] = e[i].val;
        else
          sum[1] = e[i].val;
      }
    }
  return fxk;
}
void dfs(int u, int fa) {
  long long maxx = 0, smax = 0;
  for (int i = hed[u], v = e[i].to; i; i = e[i].nex, v = e[i].to)
    if (v != fa && !vis[v]) {
      dfs(v, u);
      d[u] = max(d[u], d[v] + e[i].val);
      if (d[v] + e[i].val > maxx)
        smax = maxx, maxx = d[v] + e[i].val;
      else if (d[v] + e[i].val > smax)
        smax = d[v] + e[i].val;
    }
  t = max(t, smax + maxx);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d%d%I64d", &u, &v, &w), add_edge(u, v, w), add_edge(v, u, w);
  }
  get_cir(1, 0);
  long long ans = 1ll << 60;
  t = 0;
  for (int i = (1); i <= (tp); ++i) dfs(s[i], 0);
  for (int i = (tp + 1); i <= (2 * tp); ++i)
    s[i] = s[i - tp], sum[i] = sum[i - tp];
  for (int i = (1); i <= (2 * tp); ++i) sum[i] += sum[i - 1];
  for (int i = (1); i <= (tp); ++i)
    a.insert(make_pair(d[s[i]] - sum[i], s[i])),
        b.insert(make_pair(d[s[i]] + sum[i], s[i]));
  for (int i = (1); i <= (tp); ++i) {
    long long D = 0;
    if (a.begin()->second == b.begin()->second) {
      set<pair<long long, int>, greater<pair<long long, int> > >::iterator
          p = a.begin(),
          q = b.begin();
      ++p;
      D = max(D, b.begin()->first + p->first);
      ++q;
      D = max(D, a.begin()->first + q->first);
    } else {
      D = a.begin()->first + b.begin()->first;
    }
    ans = min(ans, max(t, D));
    a.erase(make_pair(d[s[i]] - sum[i], s[i]));
    b.erase(make_pair(d[s[i]] + sum[i], s[i]));
    a.insert(make_pair(d[s[i + tp]] - sum[i + tp], s[i + tp]));
    b.insert(make_pair(d[s[i + tp]] + sum[i + tp], s[i + tp]));
  }
  cout << ans << endl;
  return 0;
}
