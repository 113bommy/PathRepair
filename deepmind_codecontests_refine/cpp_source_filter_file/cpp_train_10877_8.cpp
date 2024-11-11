#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x;
}
const int N = 2e5 + 5;
int now, l[N], r[N], v[N], vi[N], nex[N], vis[N], head[N];
void addedges(int x, int y) {
  nex[++now] = head[x];
  head[x] = now, v[now] = y;
}
int n, m, t, T, n1, n2, cnt;
bool dfs(int x, int ty) {
  vis[x] = cnt, vi[x] = ty;
  if (ty) {
    if (n2 < l[x] || n2 > r[x]) return false;
  } else if (n1 < l[x] || n2 > r[x])
    return false;
  for (int i = head[x]; i; i = nex[i])
    if (vis[v[i]] != cnt) {
      if (!dfs(v[i], ty ^ 1)) return false;
    } else if (vi[v[i]] != (ty ^ 1))
      return false;
  return true;
}
int main() {
  t = read(), T = read(), n = read(), m = read();
  for (int i = 1; i <= n; i++) l[i] = read(), r[i] = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    addedges(x, y), addedges(y, x);
  }
  n1 = l[1], n2 = r[1];
  for (int i = 2; i <= n; i++) n1 = max(n1, l[i]), n2 = min(n2, r[i]);
  if (n1 + n2 < t)
    n1 += t - n1 - n2;
  else if (n1 + n2 > T)
    n2 -= n1 + n2 - T;
  if (n1 < 0 || n2 < 0) {
    puts("IMPOSSIBLE");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      ++cnt;
      if (!dfs(i, 1)) {
        ++cnt;
        if (!dfs(i, 0)) {
          puts("IMPOSSIBLE");
          return 0;
        }
      }
    }
  puts("POSSIBLE");
  printf("%d %d\n", n1, n2);
  for (int i = 1; i <= n; i++) printf("%d", vi[i] + 1);
  return 0;
}
