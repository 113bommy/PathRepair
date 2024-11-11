#include <bits/stdc++.h>
const long long MaxN = 1e5 + 50;
template <class t>
inline void read(t &s) {
  s = 0;
  register long long f = 1;
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
  long long buf[21], top = 0;
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
inline bool ckmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool ckmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline long long lowbit(long long x) { return x & (-x); }
std::vector<long long> E[MaxN];
long long f[MaxN], g[MaxN], up[MaxN][21], dep[MaxN], s[MaxN][21], to[MaxN],
    a[MaxN], n, L, S;
inline void dfs(long long u, long long fa) {
  up[u][0] = fa, dep[u] = dep[fa] + 1;
  for (auto v : E[u])
    if (v != fa) s[v][0] = a[u], dfs(v, u);
}
inline void dfs2(long long u, long long fa) {
  f[u] = -1;
  for (auto v : E[u])
    if (v != fa) dfs2(v, u), ckmax(f[u], f[v] - 1), g[u] += g[v];
  if (!~f[u]) f[u] = to[u], ++g[u];
}
signed main(void) {
  read(n, L, S);
  if (!L) return std::puts("-1"), 0;
  for (long long i = 1; i <= n; ++i) {
    read(a[i]);
    if (a[i] > S) return std::puts("-1"), 0;
  }
  register long long v;
  for (long long i = 2; i <= n; ++i)
    read(v), E[i].push_back(v), E[v].push_back(i);
  dfs(1, 0);
  for (long long k = 1; k < 21; ++k)
    for (long long i = 1; i <= n; ++i)
      up[i][k] = up[up[i][k - 1]][k - 1],
      s[i][k] = s[i][k - 1] + s[up[i][k - 1]][k - 1];
  for (long long i = 1; i <= n; ++i) {
    register long long pos = i, nl = 0, ns = a[i];
    for (long long k = 20; ~k; --k)
      if (up[pos][k] && nl + (1 << k) < L && ns + s[pos][k] <= S)
        nl += (1 << k), ns += s[pos][k], pos = up[pos][k];
    to[i] = nl;
  }
  dfs2(1, 0);
  write(g[1]), std::puts("");
  return 0;
}
