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
const int N = 2.5e5 + 7;
const int M = 5e5 + 7;
int n, m, k, nk;
int fz[N][3], f[N], chk[N], vis[N], dep[N];
struct Edge {
  int to, ne;
} g[M << 1];
int head[N], tot;
inline void addedge(int x, int y) {
  g[++tot].to = y, g[tot].ne = head[x], head[x] = tot;
}
inline void adde(int x, int y) { addedge(x, y), addedge(y, x); }
inline void dfs(int x, int fa = 0) {
  f[x] = fa, vis[x] = 1, dep[x] = dep[fa] + 1;
  int &c = chk[x] = 1;
  for (int i = head[x], y = g[i].to; i; i = g[i].ne, y = g[i].to)
    if (!vis[y])
      c = 0, dfs(y, x);
    else if (y != fa && fz[x][0] < 2)
      fz[x][++fz[x][0]] = y;
}
inline void work() {
  dfs(1);
  for (int i = 1; i <= n; ++i)
    if (dep[i] >= nk) {
      puts("PATH");
      printf("%d\n", dep[i]);
      for (int x = i; x; x = f[x]) printf("%d%c", x, " \n"[!f[x]]);
      return;
    }
  puts("CYCLES");
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (chk[i]) {
      ++cnt;
      if (dep[fz[i][1]] < dep[fz[i][2]]) std::swap(fz[i][1], fz[i][2]);
      if ((dep[i] - dep[fz[i][1]]) % 3 != 2) {
        int ans = 0;
        for (int x = i; x != f[fz[i][1]]; x = f[x]) ++ans;
        printf("%d\n", ans);
        for (int x = i; x != f[fz[i][1]]; x = f[x])
          printf("%d%c", x, " \n"[x == fz[i][1]]);
      } else {
        if ((dep[i] - dep[fz[i][2]]) % 3 != 2) {
          int ans = 0;
          for (int x = i; x != f[fz[i][2]]; x = f[x]) ++ans;
          printf("%d\n", ans);
          for (int x = i; x != f[fz[i][2]]; x = f[x])
            printf("%d%c", x, " \n"[x == fz[i][2]]);
        } else {
          int ans = 1;
          for (int x = fz[i][1]; x != f[fz[i][2]]; x = f[x]) ++ans;
          printf("%d\n", ans);
          for (int x = fz[i][1]; x != f[fz[i][2]]; x = f[x]) printf("%d ", x);
          printf("%d\n", i);
        }
      }
      if (cnt >= k) return;
    }
  assert(cnt >= k);
}
inline void init() {
  read(n), read(m), read(k), nk = (n - 1) / k + 1;
  int x, y;
  for (int i = 1; i <= m; ++i) read(x), read(y), adde(x, y);
}
int main() {
  init();
  work();
  fclose(stdin), fclose(stdout);
  return 0;
}
