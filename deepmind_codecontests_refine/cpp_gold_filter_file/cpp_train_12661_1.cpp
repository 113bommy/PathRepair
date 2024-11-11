#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
const int mod = 1e9 + 7;
vector<int> nd;
map<int, int> vi;
int n, m, q, ecnt, sz[1010];
struct ED {
  int x, y;
} e[111];
void _label(int x) {
  while (x) {
    if (vi.count(x)) return;
    vi[x] = nd.size(), nd.push_back(x);
    x >>= 1;
  }
}
int cal_sz(int u) {
  int ls = u, rs = u, d = 1;
  while (rs < n) d++, ls = ls << 1, rs = rs << 1 | 1;
  int res = (1 << d) - 1;
  if (ls <= n && rs >= n) res -= rs - n;
  if (n < ls) res -= (1 << d - 1);
  return res;
}
vector<pair<int, int> > G[1010];
void dfs1(int u, int last) {
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i].first;
    if (v == last) continue;
    sz[u] -= sz[v];
    dfs1(v, u);
  }
}
int vis[1010], start_num, start_pos, Ans;
void dfs(int u, int eid) {
  vis[u] = 1;
  Ans = (Ans + start_num * (long long)sz[u]) % mod;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i].first;
    if (vis[v] || G[u][i].second == eid) continue;
    dfs(v, G[u][i].second);
  }
  vis[u] = 0;
}
int main() {
  rd(n), rd(m);
  _label(n);
  for (int i = 1; i <= m; ++i)
    rd(e[i].x), rd(e[i].y), _label(e[i].x), _label(e[i].y);
  q = nd.size();
  for (int i = 0; i < q; ++i) {
    int u = nd[i];
    if (u != 1) {
      int f = vi[u >> 1];
      G[f].push_back(make_pair(i, ++ecnt)), G[i].push_back(make_pair(f, ecnt));
    }
  }
  for (int i = 0; i < q; ++i) {
    sz[i] = cal_sz(nd[i]);
  }
  dfs1(vi[1], -1);
  for (int i = 1; i <= m; ++i) {
    int x = vi[e[i].x], y = vi[e[i].y];
    G[x].push_back(make_pair(y, ++ecnt)), G[y].push_back(make_pair(x, ecnt));
  }
  for (int i = 0; i < q; ++i) {
    start_num = sz[i], start_pos = i;
    dfs(i, 0);
  }
  printf("%d\n", Ans);
  return 0;
}
