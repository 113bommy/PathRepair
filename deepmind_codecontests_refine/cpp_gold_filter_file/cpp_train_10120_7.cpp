#include <bits/stdc++.h>
using namespace std;
namespace Fread {
const int MAXN = 1 << 20;
char buffer[MAXN], *S, *T;
inline char getchar() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, MAXN, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
}  // namespace Fread
inline int read() {
  int f = 1, x = 0;
  char ch = Fread::getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = Fread::getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = Fread::getchar();
  }
  return x * f;
}
inline long long readll() {
  long long f = 1, x = 0;
  char ch = Fread::getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = Fread::getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = Fread::getchar();
  }
  return x * f;
}
const int MAXN = 5e5 + 5;
int n, m;
struct EDGE {
  int nxt, frm, to;
} edge[MAXN << 2];
int head[MAXN], tot;
inline void add_edge(int u, int v) {
  edge[++tot].nxt = head[u], edge[tot].frm = u, edge[tot].to = v, head[u] = tot;
}
int fa[MAXN], fe[MAXN], cir[MAXN], cnt, t[MAXN], f[MAXN], g[MAXN << 1];
bool vis[MAXN], ins[MAXN];
void check() {
  int mn = m + 1, mnp = 0, mx = 0;
  for (int i = 1; i <= cnt; ++i) {
    mn = min(mn, cir[i] >> 1);
    if ((cir[i] >> 1) == mn) mnp = i;
    mx = max(mx, cir[i] >> 1);
  }
  static int tmp[MAXN];
  int tt = 0;
  for (int i = mnp; i <= cnt; ++i) tmp[++tt] = cir[i];
  for (int i = 1; i < mnp; ++i) tmp[++tt] = cir[i];
  for (int i = 1; i <= cnt; ++i) cir[i] = tmp[i];
  int pos1 = 0, pos2 = 0;
  for (int i = 1; i <= cnt; ++i) {
    if (i == cnt || (cir[i + 1] >> 1) < (cir[i] >> 1)) {
      pos1 = i;
      break;
    }
  }
  for (int i = cnt; i >= 1; --i) {
    if (i == 1 || (cir[i - 1] >> 1) < (cir[i] >> 1)) {
      pos2 = i;
      break;
    }
  }
  assert(pos1 <= pos2);
  if (pos1 == pos2) t[mn] = mx;
}
void dfs(int u) {
  vis[u] = ins[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa[u]) continue;
    if (!vis[v]) {
      fa[v] = u;
      fe[v] = i;
      dfs(v);
    } else if (ins[v]) {
      cnt = 0;
      for (int j = u; j != v; j = fa[j]) cir[++cnt] = fe[j];
      cir[++cnt] = i;
      check();
    }
  }
  ins[u] = 0;
}
int get_fa(int x) { return x == fa[x] ? x : (fa[x] = get_fa(fa[x])); }
int main() {
  tot = 1;
  n = read(), m = read();
  for (int i = 1, u, v; i <= m; ++i)
    u = read(), v = read(), add_edge(u, v), add_edge(v, u);
  dfs(1);
  for (int i = 1; i <= n; ++i) fa[i] = i, f[i] = 1;
  for (int i = m, u, v; i >= 1; --i) {
    int uu = get_fa(u = edge[i << 1].frm), vv = get_fa(v = edge[i << 1].to);
    if (uu != vv) {
      f[u] = f[v] = g[i] = f[u] + f[v];
      fa[uu] = vv;
    } else {
      f[u] = f[v] = g[i] = f[u] + f[v] - g[t[i]];
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", f[i] - 1);
  puts("");
  return 0;
}
