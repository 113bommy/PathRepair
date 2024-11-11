#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 4e5 + 10;
int n, m, col[maxn], fa[maxn];
long long ans[maxn];
struct LCT {
  int son[maxn][2], fa[maxn], siz[maxn], siz2[maxn];
  long long Siz2[maxn];
  inline int getw(int x) { return son[fa[x]][1] == x; }
  inline bool notrt(int x) { return son[fa[x]][0] == x or son[fa[x]][1] == x; }
  inline void pushup(int x) {
    siz[x] = siz[son[x][0]] + siz[son[x][1]] + siz2[x] + 1;
  }
  inline void rotate(int x) {
    int y = fa[x], z = fa[y], w = getw(x), s = son[x][!w];
    if (notrt(y)) son[z][getw(y)] = x;
    son[y][w] = s, son[x][!w] = y;
    if (s) fa[s] = y;
    fa[y] = x;
    fa[x] = z;
    pushup(y);
  }
  inline void splay(int x) {
    while (notrt(x)) {
      int y = fa[x];
      if (notrt(y)) rotate(getw(x) ^ getw(y) ? x : y);
      rotate(x);
    }
    pushup(x);
  }
  inline void access(int x) {
    for (int y = 0; x; y = x, x = fa[x])
      splay(x), siz2[x] += siz[son[x][1]] - siz[y],
          Siz2[x] +=
          1ll * siz[son[x][1]] * siz[son[x][1]] - 1ll * siz[y] * siz[y],
          son[x][1] = y, pushup(x);
  }
  inline int findrt(int x) {
    access(x), splay(x);
    while (son[x][0]) x = son[x][0];
    splay(x);
    return x;
  }
  inline void link(int x) {
    splay(x);
    int y = fa[x] = star::fa[x];
    access(y), splay(y), siz2[y] += siz[x], Siz2[y] += 1ll * siz[x] * siz[x];
    pushup(x);
  }
  inline void cut(int x) {
    access(x), splay(x), son[x][0] = fa[son[x][0]] = 0, pushup(x);
  }
  inline void rev(int x) {
    col[x] ^= 1;
    if (col[x])
      cut(x);
    else
      link(x);
  }
  inline int query(int x) { return siz[son[findrt(x)][1]]; }
  inline long long query2(int x) { return access(x), Siz2[x]; }
} S;
struct operation {
  int x, op, t;
};
vector<operation> q[maxn];
int ecnt, head[maxn], to[maxn << 1], nxt[maxn << 1];
inline void addedge(int a, int b) {
  to[++ecnt] = b, nxt[ecnt] = head[a], head[a] = ecnt;
  to[++ecnt] = a, nxt[ecnt] = head[b], head[b] = ecnt;
}
void dfs(int x, int f) {
  fa[x] = f;
  S.link(x);
  for (int u, i = head[x]; i; i = nxt[i])
    if ((u = to[i]) != f) dfs(u, x);
}
inline void work() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    q[col[i] = read()].push_back((operation){i, 1, 0});
  for (int i = 1; i < n; i++) addedge(read(), read());
  dfs(1, n + 1);
  for (int a, i = 1; i <= m; i++)
    a = read(), q[col[a]].push_back((operation){a, 0, i}),
    q[col[a] = read()].push_back((operation){a, 1, i});
  memset(col, 0, sizeof col);
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (auto &&x : q[i]) {
      ans[x.t] -= sum;
      if (x.op) {
        int zp = S.query(x.x);
        sum += 1ll * zp * zp;
        S.rev(x.x);
        zp = S.query(fa[x.x]);
        sum -= 1ll * zp * zp + S.query2(x.x);
      } else {
        int zp = S.query(fa[x.x]);
        sum += 1ll * zp * zp + S.query2(x.x);
        S.rev(x.x);
        zp = S.query(x.x);
        sum -= 1ll * zp * zp;
      }
      ans[x.t] += sum;
    }
    for (auto &&x : q[i]) S.rev(x.x);
  }
  for (int i = 1; i <= m; i++) ans[i] += ans[i - 1];
  for (int i = 0; i <= m; i++) printf("%lld\n", ans[i]);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
