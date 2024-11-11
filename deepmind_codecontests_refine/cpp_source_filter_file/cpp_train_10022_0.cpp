#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, m;
char a[N][N];
inline int id(int k, int x, int y) {
  return (n + 1) * (m + 1) * k + (x - 1) * (m + 1) + y;
}
int s, t;
const int P = 85005;
const int E = 200005;
int to[E], nx[E], h[P], w[E], tot = 1;
bool vis[P];
inline void add(int a, int b, int c) {
  to[++tot] = b;
  nx[tot] = h[a];
  h[a] = tot;
  w[tot] = c;
}
inline void link(int a, int b, int c) {
  add(a, b, c);
  add(b, a, 0);
}
int d[P], cur[P];
inline bool bfs() {
  memset(d, 0, sizeof d);
  memset(cur, 0, sizeof cur);
  queue<int> Q;
  d[s] = 1;
  cur[s] = h[s];
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = h[u]; i; i = nx[i])
      if (!d[to[i]] && w[i]) {
        d[to[i]] = d[u] + 1;
        cur[to[i]] = h[to[i]];
        Q.push(to[i]);
        if (to[i] == t) return 1;
      }
  }
  return 0;
}
inline int dfs(int u, int fl) {
  if (u == t) return fl;
  int re = fl;
  for (int i = cur[u]; i && re; i = nx[i])
    if (d[to[i]] == d[u] + 1 && w[i]) {
      int k = dfs(to[i], min(w[i], re));
      if (!k) d[to[i]] = 0;
      re -= k;
      w[i] -= k;
      w[i ^ 1] += k;
      cur[u] = i;
    }
  return fl - re;
}
const int inf = 2e9;
inline int dinic() {
  int mx = 0, tmp;
  while (bfs()) {
    if (tmp = dfs(s, inf)) mx += tmp;
  }
  return mx;
}
int cnt = 0;
inline int read() {
  int f = 0, s = 0;
  char c = getchar();
  while (c > '9' || c < '0') f = (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    s = (s << 3) + (s << 1) + (c ^ '0'), c = getchar();
  return f ? -s : s;
}
int main() {
  n = read();
  m = read();
  s = (n + 1) * (m + 1) * 2 + 1;
  t = s + 1;
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == '#') {
        cnt++;
        if (a[i - 1][j] == '#' && a[i][j - 1] == '#')
          link(id(0, i, j), id(1, i, j), 1);
        if (a[i - 1][j] == '#' && a[i][j + 1] == '#')
          link(id(0, i, j), id(1, i, j + 1), 1);
        if (a[i + 1][j] == '#' && a[i][j - 1] == '#')
          link(id(0, i + 1, j), id(1, i, j), 1);
        if (a[i + 1][j] == '#' && a[i][j + 1] == '#')
          link(id(0, i + 1, j), id(1, i, j + 1), 1);
        if (a[i - 1][j] == '#') link(s, id(0, i, j), 1), cnt--;
        if (a[i][j - 1] == '#') link(id(1, i, j), t, 1), cnt--;
      }
  int tmp = dinic();
  printf("%d", cnt + tmp);
  return 0;
}
