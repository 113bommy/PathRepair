#include <bits/stdc++.h>
template <typename A, typename B>
inline char smax(A &a, const B &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A, typename B>
inline char smin(A &a, const B &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename I>
inline void read(I &x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
  x = c & 15;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  f ? x = -x : 0;
}
const int N = 1e5 + 7;
const int M = 2e5 + 7;
int n, m;
int deg[M + N], del[M + N], ans[M + N];
struct Edge {
  int to, ne;
} g[(M + N) << 1];
int head[N], tot = 1;
inline void addedge(int x, int y) {
  g[++tot].to = y, g[tot].ne = head[x], head[x] = tot;
}
inline void adde(int x, int y) { addedge(x, y), addedge(y, x); }
inline void dfs(int x) {
  while (head[x]) {
    int i = head[x], y = g[i].to;
    head[x] = g[i].ne;
    if (del[i >> 1]) continue;
    del[i >> 1] = 1;
    dfs(y);
  }
  ans[++*ans] = x;
}
inline void work() {
  int cnt = 0;
  for (int i = 1, ls = 0; i <= n; ++i)
    if (deg[i] & 1) {
      if (ls)
        adde(ls, i), ls = 0, ++cnt;
      else
        ls = i;
    }
  dfs(1);
  --*ans;
  printf("%d\n", m + cnt + (*ans & 1));
  for (int i = 1; i + 2 <= *ans; i += 2)
    printf("%d %d\n%d %d\n", ans[i], ans[i + 1], ans[i + 2], ans[i + 1]);
  if (*ans & 1)
    printf("%d %d\n%d %d\n", ans[*ans], ans[1], ans[1], ans[1]);
  else
    printf("%d %d\n%d %d\n", ans[*ans - 1], ans[*ans], ans[1], ans[*ans]);
}
inline void init() {
  read(n), read(m);
  int x, y;
  for (int i = 1; i <= m; ++i) read(x), read(y), adde(x, y), ++deg[x], ++deg[y];
}
int main() {
  init();
  work();
  fclose(stdin), fclose(stdout);
  return 0;
}
