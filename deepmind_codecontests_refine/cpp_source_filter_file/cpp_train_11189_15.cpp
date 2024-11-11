#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
template <class T>
inline void read(T &n) {
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
           ? 0
           : *p1++);
  T w = 1, x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? 0
             : *p1++);
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)
             ? 0
             : *p1++);
  }
  n = x * w;
}
const int maxn = 100005;
int n, q, last[maxn], Next[maxn << 1], to[maxn << 1], w[maxn << 1], cnt;
inline void addedge(int x, int y, int z) {
  Next[++cnt] = last[x], last[x] = cnt;
  to[cnt] = y, w[cnt] = z;
}
struct Tree {
  int rt, f[maxn][17], g[maxn][17];
  int dis[maxn], son[maxn], len[maxn], rk[maxn];
  void dfs(int x) {
    for (int i = 1; i <= 16; i++) {
      f[x][i] = f[f[x][i - 1]][i - 1];
      g[x][i] = g[x][i - 1] + g[f[x][i - 1]][i - 1];
    }
    for (int i = last[x]; i; i = Next[i]) {
      int v = to[i];
      if (v != f[x][0]) {
        f[v][0] = x, g[v][0] = w[i];
        dfs(v);
        if (dis[v] + w[i] > dis[x]) dis[x] = dis[v] + w[i], son[x] = v;
      }
    }
    for (int i = last[x]; i; i = Next[i]) {
      int v = to[i];
      if (v != f[x][0] && v != son[x]) {
        len[v] = dis[v] + w[i];
        bot[++tot] = v;
      }
    }
  }
  int bot[maxn], tot, sum[maxn];
  void build(int _rt) {
    rt = _rt, dfs(rt);
    len[1] = dis[rt], bot[++tot] = 1;
    sort(bot + 1, bot + tot + 1, [&](int i, int j) { return len[i] > len[j]; });
    for (int i = 1; i <= tot; i++) sum[i] = sum[i - 1] + len[bot[i]];
    for (int i = 1; i <= tot; i++) {
      int x = bot[i];
      while (x) rk[x] = i, x = son[x];
    }
  }
  int query1(int x, int y) {
    int res = dis[x];
    for (int i = 16; i >= 0; i--)
      if (rk[f[x][i]] >= y) res += g[x][i], x = f[x][i];
    return sum[y - 1] + res + g[x][0];
  }
  int query2(int x, int y) {
    int res = dis[x];
    for (int i = 16; i >= 0; i--)
      if (rk[f[x][i]] > y) res += g[x][i], x = f[x][i];
    return sum[y] - dis[f[x][0]] + g[x][0] + res;
  }
  int query(int x, int y) {
    y = y * 2 - 1;
    if (y >= tot) return sum[tot];
    if (rk[x] <= y) return sum[y];
    return max(query1(x, y), query2(x, y));
  }
} T1, T2;
int dis[maxn];
void getdis(int x, int fa) {
  for (int i = last[x]; i; i = Next[i]) {
    int v = to[i];
    if (v != fa) {
      dis[v] = dis[x] + w[i];
      getdis(v, x);
    }
  }
}
int main() {
  read(n), read(q);
  for (int i = 1, x, y, z; i < n; i++) {
    read(x), read(y), read(z);
    addedge(x, y, z), addedge(y, x, z);
  }
  getdis(1, 0);
  int rt1 = 1, rt2 = 1, ans = 0;
  for (int i = 1; i <= n; i++)
    if (dis[i] > dis[rt1]) rt1 = i;
  T1.build(rt1);
  dis[rt1] = 0;
  getdis(rt1, 0);
  for (int i = 1; i <= n; i++)
    if (dis[i] > dis[rt2]) rt2 = i;
  T2.build(rt2);
  for (int i = 1, x, y; i <= q; i++) {
    read(x), read(y);
    x = (x + ans - 1) % n + 1, y = (y + ans - 1) % n + 1;
    printf("%d\n", ans = max(T1.query(x, y), T2.query(x, y)));
  }
  return 0;
}
