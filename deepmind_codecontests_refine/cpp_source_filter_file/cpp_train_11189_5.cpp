#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool Chkmax(T& x, const T& y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool Chkmin(T& x, const T& y) {
  return x > y ? x = y, true : false;
}
inline int ri() {
  int s = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = (s << 1) + (s << 3) + (c ^ 48);
    c = getchar();
  }
  return s * w;
}
const long long maxn = 2e5 + 30;
const long long maxm = 3e5 + 50;
long long n, Q;
long long head[maxn], net[maxm], to[maxm], tot, cost[maxm];
inline void add(long long x, long long y, long long z) {
  net[++tot] = head[x];
  head[x] = tot;
  to[tot] = y;
  cost[tot] = z;
}
struct T {
  long long ff[20][maxn], gg[20][maxn], dis[maxn];
  long long son[maxn], dep[maxn];
  long long top[maxn];
  void dfs1(long long x, long long fa) {
    for (long long i = head[x]; i; i = net[i]) {
      long long v = to[i];
      if (v == fa) continue;
      dis[v] = dis[x] + cost[i];
      dfs1(v, x);
    }
  }
  long long s[maxn], pop, po[maxn];
  void dfs2(long long x, long long fa) {
    ff[0][x] = fa;
    for (long long i = head[x]; i; i = net[i]) {
      long long v = to[i];
      if (v == fa) continue;
      gg[0][v] = cost[i];
      dis[v] = dis[x] + cost[i];
      dfs2(v, x);
      if (dep[v] + cost[i] > dep[x]) {
        son[x] = v, dep[x] = dep[v] + cost[i];
      }
    }
    for (long long i = head[x]; i; i = net[i]) {
      long long v = to[i];
      if (v == fa) continue;
      if (v == son[x]) continue;
      s[po[++pop] = v] = dep[v] + cost[i];
    }
  }
  long long root;
  long long cmp(long long x, long long y) { return s[x] > s[y]; }
  long long Sum[maxn], rnk[maxn];
  void findrt(long long x) {
    dfs1(x, 0);
    root = x;
    for (long long i = 1; i <= n; i++)
      if (dis[i] > dis[root]) root = i;
    dis[root] = 0;
    dfs2(root, 0);
    for (long long i = 1; i <= 20; i++) {
      for (long long j = 1; j <= n; j++) {
        ff[i][j] = ff[i - 1][ff[i - 1][j]];
        gg[i][j] = gg[i - 1][j] + gg[i - 1][ff[i - 1][j]];
      }
    }
    s[po[++pop] = root] = dep[root];
    sort(po + 1, po + 1 + pop,
         [&](long long x, long long y) { return (s[x] > s[y]); });
    for (long long i = 1; i <= pop; i++) Sum[i] = Sum[i - 1] + s[po[i]];
    for (long long i = 1; i <= pop; i++) {
      long long x = po[i], p = x;
      while (x) top[x] = p, rnk[x] = i, x = son[x];
    }
  }
  long long plan1(long long x, long long y) {
    long long z = dep[x];
    for (long long i = 20; ~i; i--) {
      if (rnk[ff[i][x]] >= y) z += gg[i][x], x = ff[i][x];
    }
    return Sum[y - 1] + z + gg[0][x];
  }
  long long plan2(long long x, long long y) {
    long long z = dep[x];
    for (long long i = 20; ~i; i--) {
      if (rnk[ff[i][x]] > y) z += gg[i][x], x = ff[i][x];
    }
    return Sum[y] - dep[ff[0][x]] + z + gg[0][x];
  }
  long long solve(long long x, long long y) {
    y = 2 * y - 1;
    return rnk[x] <= y ? Sum[y] : max(plan1(x, y), plan2(x, y));
  }
} t[3];
long long du[maxn], zxy;
signed main() {
  n = ri();
  Q = ri();
  long long asd = 0;
  for (long long i = 1; i < n; i++) {
    long long x = ri(), y = ri(), z = ri();
    add(x, y, z);
    add(y, x, z);
    du[x]++, du[y]++;
    asd += z;
  }
  for (long long i = 1; i <= n; i++)
    if (du[i] == 1) zxy++;
  t[0].findrt(1);
  t[1].findrt(t[0].root);
  long long lastans = 0;
  for (long long i = 1; i <= Q; i++) {
    long long x = ri(), y = ri();
    if (i != 1) x = ((x + lastans - 1) % n) + 1;
    if (i != 1) y = ((y + lastans - 1) % n) + 1;
    lastans = (2 * y >= zxy ? asd : max(t[0].solve(x, y), t[1].solve(x, y)));
    printf("%lld\n", lastans);
  }
  return 0;
}
