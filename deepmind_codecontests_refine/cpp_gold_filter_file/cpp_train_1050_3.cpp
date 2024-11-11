#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 2e6 + 5;
int n, tot, head[N], a[N], b[N], num[N], cnt;
struct edge {
  int link, next;
} e[N];
inline void init() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    b[i] = read();
    num[++cnt] = a[i];
    num[++cnt] = b[i];
  }
  sort(num + 1, num + 1 + cnt);
  cnt = unique(num + 1, num + 1 + cnt) - num - 1;
}
inline void add_edge(int u, int v) {
  e[++tot] = (edge){v, head[u]};
  head[u] = tot;
}
inline void insert(int u, int v) {
  add_edge(u, v);
  add_edge(v, u);
}
bool vis[N];
int ans, ed, sz, mx1, mx2;
void dfs(int u) {
  if (vis[u]) return;
  if (u > mx1)
    mx2 = mx1, mx1 = u;
  else if (u > mx2)
    mx2 = u;
  vis[u] = 1;
  sz++;
  for (int i = head[u]; i; i = e[i].next) {
    ed++;
    dfs(e[i].link);
  }
}
inline void solve() {
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(num + 1, num + 1 + cnt, a[i]) - num;
    b[i] = lower_bound(num + 1, num + 1 + cnt, b[i]) - num;
    insert(a[i], b[i]);
  }
  ans = 0;
  for (int i = cnt; i; i--) {
    if (!vis[i]) {
      mx2 = mx1 = sz = ed = 0;
      dfs(i);
      if (ed / 2 > sz) {
        puts("-1");
        return;
      } else {
        if (ed / 2 == sz)
          ans = max(ans, mx1);
        else
          ans = max(ans, mx2);
      }
    }
  }
  writeln(num[ans]);
}
int main() {
  init();
  solve();
  return 0;
}
