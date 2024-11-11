#include <bits/stdc++.h>
int read() {
  static int ch, x;
  while ((ch = getchar()) < 48) {
  }
  x = ch ^ 48;
  while ((ch = getchar()) >= 48) x = (((x << 2) + x) << 1) + (ch ^ 48);
  return x;
}
struct edge {
  int next, to;
} e[200010 << 1];
int ei, cnt;
int head[200010], dep[200010], fa[200010], fx[200010], fy[200010], mk[200010];
bool vis[200010];
void dfs(const int &f) {
  vis[f] = true;
  dep[f] = dep[fa[f]] + 1;
  for (int i = head[f]; i; i = e[i].next) {
    const int t = e[i].to;
    if (vis[t]) {
      if (t != fa[f] && dep[f] < dep[t]) {
        ++cnt;
        fx[cnt] = f;
        fy[cnt] = t;
      }
    } else {
      fa[t] = f;
      dfs(t);
    }
  }
}
bool solve(const int &rt) {
  cnt = 0;
  dfs(rt);
  for (int i = 1; i <= cnt; ++i) {
    int px = fx[i], py = fy[i];
    while (dep[py] > dep[px]) {
      if (mk[py]) {
        puts("YES");
        const int f = py, j = mk[f];
        while (mk[py] == j) py = fa[py];
        const int t = py;
        cnt = 0;
        for (int x = f; x != t; x = fa[x]) head[++cnt] = x;
        printf("%d %d", dep[f] - dep[t] + 1, t);
        for (int i = cnt; i >= 1; --i) printf(" %d", head[i]);
        putchar(10);
        printf("%d ", dep[fy[i]] - dep[fx[i]] + dep[t] - dep[f] + 2);
        for (int x = t; x != fx[i]; x = fa[x]) printf("%d ", x);
        printf("%d", fx[i]);
        for (int x = fy[i]; x != f; x = fa[x]) printf(" %d", x);
        printf(" %d\n%d ", f, dep[fy[j]] - dep[fx[j]] + dep[t] - dep[f] + 2);
        for (int x = t; x != fx[j]; x = fa[x]) printf("%d ", x);
        printf("%d", fx[j]);
        for (int x = fy[j]; x != f; x = fa[x]) printf(" %d", x);
        printf(" %d\n", f);
        return true;
      }
      mk[py] = i;
      py = fa[py];
    }
  }
  return false;
}
int main() {
  const int n = read();
  for (int m = read(); m--;) {
    const int x = read(), y = read();
    (e[++ei].next = head[x], e[ei].to = (y), head[x] = ei);
    (e[++ei].next = head[y], e[ei].to = (x), head[y] = ei);
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i] && solve(i)) return 0;
  puts("NO");
  return 0;
}
