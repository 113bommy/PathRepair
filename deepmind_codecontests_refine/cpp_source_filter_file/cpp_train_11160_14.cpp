#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
const int mod = 1000000007;
int n, a[maxn], dep[maxn], fa[maxn], in[maxn], out[maxn], to[maxn];
long long fac[maxn];
bool vis[maxn];
vector<int> g[maxn], p, q;
vector<pair<int, int> > e[maxn];
inline void fail() {
  printf("0\n");
  exit(0);
}
void dfs(int x, int ff) {
  fa[x] = ff, dep[x] = dep[ff] + 1;
  for (auto y : g[x])
    if (y != ff) dfs(y, x);
}
inline void getpath(int x, int y) {
  p.clear(), q.clear();
  while (dep[x] > dep[y]) p.push_back(x), x = fa[x];
  while (dep[x] < dep[y]) q.push_back(y), y = fa[y];
  if (x == y) {
    p.push_back(x);
    reverse(q.begin(), q.end());
    for (auto it : q) p.push_back(it);
    return;
  }
  while (fa[x] != fa[y]) p.push_back(x), q.push_back(y), x = fa[x], y = fa[y];
  p.push_back(x), q.push_back(y), p.push_back(fa[x]);
  reverse(q.begin(), q.end());
  for (auto it : q) p.push_back(it);
}
inline int solve(vector<int> &g, vector<pair<int, int> > &e) {
  g.push_back(0), g.push_back(n + 1);
  for (auto x : e) out[x.first]++, in[x.second]++, to[x.first] = x.second;
  for (auto x : g)
    if (in[x] > 1 || out[x] > 1) fail();
  for (auto x : g)
    if (!vis[x]) {
      int y = x;
      vis[x] = 1;
      while (to[y] != -1 && !vis[to[y]]) y = to[y], vis[y] = 1;
      if (to[y] == x) fail();
    }
  int x = 0;
  while (to[x] != -1) x = to[x];
  int ans = (int)g.size() - (int)e.size();
  if (x == n + 1 && ans > 1) fail();
  for (auto x : g) in[x] = out[x] = vis[x] = 0, to[x] = -1;
  return ans - 2;
}
int main() {
  fac[0] = fac[1] = 1;
  for (int i = 2; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
  scanf("%d", &n);
  int x, y;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  dfs(1, 0);
  int totdis = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) continue;
    if (i == a[i]) fail();
    getpath(i, a[i]);
    totdis += (int)p.size() - 1;
    if (totdis > 2 * n - 2) fail();
    int siz = p.size(), st = p[0], ed = p[siz - 1];
    e[st].push_back(pair<int, int>(0, p[1]));
    e[ed].push_back(pair<int, int>(p[siz - 2], n + 1));
    for (int j = 1; j < siz - 1; j++)
      e[p[j]].push_back(pair<int, int>(p[j - 1], p[j + 1]));
  }
  for (int i = 0; i <= n + 1; i++) to[i] = -1;
  long long ans = 1;
  for (int i = 1; i <= n; i++) (ans *= fac[solve(g[i], e[i])]) %= mod;
  printf("%lld\n", ans);
  return 0;
}
