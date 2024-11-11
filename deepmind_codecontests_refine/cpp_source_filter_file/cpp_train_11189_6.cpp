#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 100010, M = N;
int n, m, k, sum, ans;
;
struct edge {
  int nxt, to, w;
} e[M << 1];
int head[N], cnt = 1 ^ 1;
void add(int u, int v, int w = 0) {
  e[++cnt].w = w, e[cnt].to = v, e[cnt].nxt = head[u];
  head[u] = cnt;
}
void add_edge(int u, int v, int w = 0) { add(u, v, w), add(v, u, w * 1); };
struct Tree {
  int root, f[N][20], g[N][20], d[N], h[N], son[N], top[N], rnk[N];
  int len[N], s[N], id[N], tot;
  void dfs1(int u, int fa) {
    for (int i = head[u], v; i; i = e[i].nxt)
      if ((v = e[i].to) ^ fa) d[v] = d[u] + e[i].w, dfs1(v, u);
  }
  void dfs2(int u) {
    for (int i = head[u], v; i; i = e[i].nxt)
      if ((v = e[i].to) ^ f[u][0]) {
        f[v][0] = u, g[u][0] = e[i].w;
        for (int i = 0; i < 20; i++)
          f[v][i + 1] = f[f[v][i]][i], g[v][i + 1] = g[v][i] + g[f[v][i]][i];
        d[v] = d[u] + e[i].w, dfs2(v);
        if (h[v] + e[i].w > h[u]) h[u] = h[v] + e[i].w, son[u] = v;
      }
    for (int i = head[u], v; i; i = e[i].nxt)
      if ((v = e[i].to) ^ f[u][0] && v ^ son[u])
        len[id[++tot] = v] = h[v] + e[i].w;
  }
  void init(int u) {
    dfs1(u, 0), root = u;
    for (int i = 1; i <= n; i++)
      if (d[i] > d[root]) root = i;
    d[root] = 0, dfs2(root), len[id[++tot] = root] = h[root];
    sort(id + 1, id + tot + 1, [&](int u, int v) { return len[u] > len[v]; });
    for (int i = 1; i <= tot; i++) s[i] = s[i - 1] + len[id[i]];
    for (int i = 1; i <= tot; i++) {
      int now = id[i], x = now;
      while (now) top[now] = x, rnk[now] = i, now = son[now];
    }
  }
  int plan1(int x, int y) {
    int z = h[x];
    for (int i = 19; ~i; i--)
      if (rnk[f[x][i]] >= y) z += g[x][i], x = f[x][i];
    return s[y - 1] + z + g[x][0];
  }
  int plan2(int x, int y) {
    int z = h[x];
    for (int i = 19; ~i; i--)
      if (rnk[f[x][i]] > y) z += g[x][i], x = f[x][i];
    return s[y] - h[f[x][0]] + z + g[x][0];
  }
  int ask(int x, int y) {
    y = 2 * y - 1;
    return rnk[x] <= y ? s[y] : max(plan1(x, y), plan2(x, y));
  }
} T1, T2;
int main() {
  n = read(), m = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read(), w = read();
    sum += w, add_edge(u, v, w);
  }
  for (int i = 1; i <= n; i++) k += (!e[head[i]].nxt);
  T1.init(1), T2.init(T1.root);
  while (m--) {
    int x = (read() + ans - 1) % n + 1, y = (read() + ans - 1) % n + 1;
    print(ans = (2 * y >= k ? sum : max(T1.ask(x, y), T2.ask(x, y)))),
        putchar('\n');
  }
}
