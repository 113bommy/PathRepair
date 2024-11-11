#include <bits/stdc++.h>
using namespace std;
int d[300005], x[300005], fa[300005], tf[300005];
int head[300005], nxt[600005], v[600005], tot = 0, ans = 0, n, m;
bool p[300005], vis[300005];
inline void add(int a, int b) {
  tot++;
  nxt[tot] = head[a];
  head[a] = tot;
  v[tot] = b;
}
inline int read() {
  int x = 0, f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
  return x;
}
void dfs(int pos) {
  vis[pos] = 1;
  for (int i = head[pos]; i; i = nxt[i]) {
    if (!vis[v[i]]) {
      fa[v[i]] = pos;
      tf[v[i]] = (i + 1) >> 1;
      dfs(v[i]);
    }
  }
  if (x[pos] ^ d[pos]) {
    x[fa[pos]] ^= 1;
    ans++;
    p[tf[pos]] = 1;
  }
}
inline void put(int p) {
  int cnt = 0, a[10];
  while (p) {
    a[++cnt] = p % 10;
    p /= 10;
  }
  while (cnt--) {
    putchar(a[cnt] + '0');
  }
  putchar(' ');
}
int main() {
  int s = 0, tag = 0, i, u, v;
  n = read();
  m = read();
  for (i = 1; i <= n; i++) {
    d[i] = read();
    if (d[i] == -1) {
      tag = 1;
    } else {
      s += d[i];
    }
  }
  if ((s & 1) && (!tag)) {
    puts("-1");
    return 0;
  }
  if (s & 1) {
    for (i = 1; i <= n; i++) {
      if (d[i] == -1) {
        d[i] = 1;
        break;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (d[i] == -1) {
      d[i] = 0;
    }
  }
  for (i = 1; i <= m; i++) {
    u = read();
    v = read();
    add(u, v);
    add(v, u);
  }
  dfs(1);
  if (ans == 0) {
    puts("0");
    return 0;
  }
  put(ans);
  for (i = 1; i <= m; i++) {
    if (p[i]) put(i);
  }
  return 0;
}
