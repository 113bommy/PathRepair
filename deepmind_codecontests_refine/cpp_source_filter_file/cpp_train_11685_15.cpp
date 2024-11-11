#include <bits/stdc++.h>
using namespace std;
int ans, n, a[1000005], b[1000005];
int head[100005], to[200005], nxt[200005], cnt;
int u, v, s[100005], mx;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x;
}
inline void addedge(int u, int v) {
  s[u]++;
  to[++cnt] = v;
  nxt[cnt] = head[u];
  head[u] = cnt;
  return;
}
inline void write(int x) {
  if (x < 10)
    putchar(x + 48);
  else
    write(x / 10), putchar(x % 10 + 48);
  return;
}
inline void out(int now, int t) {
  a[++ans] = now;
  b[ans] = t;
  return;
}
void dfs(int now, int ti, int fa) {
  int t = ti;
  out(now, t);
  for (int i = head[now]; i; i = nxt[i])
    if (to[i] != fa) {
      if (t == mx) t = mx - s[now] - 1, out(now, t);
      t++;
      dfs(to[i], t, now);
      out(now, t);
    }
  if (now == 1) return;
  if (t == ti - 1) return;
  out(now, ti - 1);
  return;
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    u = read();
    v = read();
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1; i <= n; i++) mx = max(mx, s[i]);
  dfs(1, 0, 0);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) {
    write(a[i]);
    putchar(' ');
    write(b[i]);
    putchar('\n');
  }
  return 0;
}
