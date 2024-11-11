#include <bits/stdc++.h>
inline int rint() {
  int x = 0, f = 1;
  char s = getchar();
  for (; s < '0' || '9' < s; s = getchar()) f = s == '-' ? -f : f;
  for (; '0' <= s && s <= '9'; s = getchar()) x = x * 10 + (s ^ '0');
  return x * f;
}
template <typename Tp>
inline void wint(Tp x) {
  if (x < 0) putchar('-'), x = ~x + 1;
  if (9 < x) wint(x / 10);
  putchar(x % 10 ^ '0');
}
const int MAXN = 1e5, MAXLG = 17;
int n, S, T, ecnt, len, head[MAXN + 5];
int lca, fa[MAXN + 5][MAXLG + 5], mxd[MAXN + 5], mxu[MAXN + 5], scd[MAXN + 5],
    dep[MAXN + 5];
bool vis[MAXN + 5];
struct Edge {
  int to, nxt;
} graph[MAXN * 2 + 5];
inline void link(const int s, const int t) {
  graph[++ecnt] = {t, head[s]};
  head[s] = ecnt;
}
inline void clear() {
  ecnt = 0;
  for (int i = 1; i <= n; ++i) fa[i][0] = head[i] = vis[i] = 0;
}
inline void init(const int u) {
  mxd[u] = scd[u] = 0, mxu[u] = u;
  for (int i = head[u], v; i; i = graph[i].nxt) {
    if ((v = graph[i].to) ^ fa[u][0]) {
      dep[v] = dep[fa[v][0] = u] + 1, init(v);
      if (mxd[v] > mxd[u])
        mxu[u] = mxu[v], scd[u] = mxd[u], mxd[u] = mxd[v];
      else if (mxd[v] > scd[u])
        scd[u] = mxd[u];
    }
  }
  if (mxd[u]++) ++scd[u];
}
inline int calcLen(const int u, const int f) {
  if (u == T) return 1;
  for (int i = head[u], v, t; i; i = graph[i].nxt) {
    if ((v = graph[i].to) ^ f && ~(t = calcLen(v, u))) {
      return t + 1;
    }
  }
  return -1;
}
inline int findTurn(const int u, int up) {
  int cnt = up >= len;
  for (int i = head[u], v; i; i = graph[i].nxt) {
    if ((v = graph[i].to) ^ fa[u][0]) {
      cnt += mxd[v] + 1 >= len;
    }
  }
  if (cnt >= 3) return u;
  ++up;
  for (int i = head[u], v; i; i = graph[i].nxt) {
    if ((v = graph[i].to) ^ fa[u][0]) {
      int t, dup = std::max(up, (mxd[v] + 1 == mxd[u] ? scd[u] : mxd[u]) + 1);
      if (~(t = findTurn(v, dup))) return t;
    }
  }
  return -1;
}
inline int climb(int u, const int k) {
  for (int i = 17; ~i; --i) {
    if ((k >> i) & 1) {
      u = fa[u][i];
    }
  }
  return u;
}
inline bool travel(const int hd, const int tl) {
  if (vis[mxu[hd]]) return false;
  int nh = mxu[hd], d = dep[nh] - dep[hd], nt = climb(tl, d);
  if (!nt || dep[nt] <= dep[lca]) return true;
  return vis[nh] = true, travel(nt, nh);
}
int main() {
  for (int times = rint(); times--;) {
    clear();
    n = rint(), S = rint(), T = rint();
    for (int i = 1, u, v; i < n; ++i) {
      u = rint(), v = rint();
      link(u, v), link(v, u);
    }
    len = calcLen(S, 0);
    dep[1] = 1, init(1);
    int rt = findTurn(1, 0);
    if (!~rt) {
      puts("NO");
      continue;
    }
    fa[rt][0] = 0, dep[rt] = 1, init(rt);
    for (int j = 1; j <= 17; ++j) {
      for (int i = 1; i <= n; ++i) {
        fa[i][j] = fa[fa[i][j - 1]][j - 1];
      }
    }
    if (climb(S, len - 1) == T || climb(T, len - 1) == S) {
      puts("YES");
      continue;
    }
    int u = S, v = T;
    if (dep[u] < dep[v]) u ^= v ^= u ^= v;
    for (int i = 17; ~i; --i)
      if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    for (int i = 17; ~i; --i)
      if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
    lca = u == v ? u : fa[u][0];
    puts(travel(S, T) ? "YES" : "NO");
  }
  return 0;
}
