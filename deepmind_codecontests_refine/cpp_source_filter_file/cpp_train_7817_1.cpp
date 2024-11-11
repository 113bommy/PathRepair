#include <bits/stdc++.h>
const int MaxN = 4e5 + 50;
template <class t>
inline void read(t &s) {
  s = 0;
  register int f = 1;
  register char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  s *= f;
  return;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0) putchar('-'), x = -x;
  int buf[21], top = 0;
  while (x) buf[++top] = x % 10, x /= 10;
  if (!top) buf[++top] = 0;
  while (top) putchar(buf[top--] ^ '0');
  return;
}
inline void setIn(std::string s) {
  freopen(s.c_str(), "r", stdin);
  return;
}
inline void setOut(std::string s) {
  freopen(s.c_str(), "w", stdout);
  return;
}
inline void setIO(std::string s = "") {
  setIn(s + ".in");
  setOut(s + ".out");
  return;
}
template <class t>
inline bool checkmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool checkmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline int lowbit(int x) { return x & (-x); }
std::vector<int> E[MaxN], G[MaxN];
int dfn[MaxN], low[MaxN], vis[MaxN], sta[MaxN], top, dfncnt, bcc, n, m;
inline void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++dfncnt;
  sta[top++] = u, vis[u] = 1;
  for (auto v : E[u])
    if (v != fa) {
      if (!dfn[v]) {
        tarjan(v, u);
        checkmin(low[u], low[v]);
        if (low[v] >= dfn[u]) {
          ++bcc;
          do
            vis[sta[--top]] = 0, G[bcc].push_back(sta[top]),
            G[sta[top]].push_back(bcc);
          while (sta[top] != v);
          G[u].push_back(bcc), G[bcc].push_back(u);
        }
      } else if (vis[v])
        checkmin(low[u], low[v]);
    }
}
namespace SP {
int up[MaxN][21], LG[MaxN], dep[MaxN], dfn[MaxN], dfncnt;
inline void dfs(int u, int fa) {
  up[dfn[u] = ++dfncnt][0] = u, dep[u] = dep[fa] + 1;
  for (auto v : G[u])
    if (v != fa) dfs(v, u), up[++dfncnt][0] = u;
}
inline int min(int u, int v) { return dep[u] < dep[v] ? u : v; }
inline void init() {
  for (int i = 2; i < MaxN; ++i) LG[i] = LG[i >> 1] + 1;
  dfs(1, 0);
  for (int k = 1; k < 21; ++k)
    for (int i = 1; i + (1 << k) - 1 <= dfncnt; ++i)
      up[i][k] = min(up[i][k - 1], up[i + (1 << (k - 1))][k - 1]);
}
inline int ask(int u, int v) {
  u = dfn[u], v = dfn[v];
  if (u > v) std::swap(u, v);
  register int k = LG[v - u + 1];
  return min(up[u][k], up[v - (1 << k) + 1][k]);
}
inline int dis(int u, int v) { return dep[u] + dep[v] - 2 * dep[ask(u, v)]; }
}  // namespace SP
signed main(void) {
  int q;
  read(n, m, q), bcc = n;
  register int u, v;
  for (int i = 1; i <= m; ++i) read(u, v), E[u].push_back(v), E[v].push_back(u);
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i, 0);
  SP::init();
  while (q--) read(u, v), write(SP::dis(u, v) >> 1), std::puts("");
  return 0;
}
