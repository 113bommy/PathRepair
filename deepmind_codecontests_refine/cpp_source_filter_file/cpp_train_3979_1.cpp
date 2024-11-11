#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * flag;
}
int wl, x, y, head[3010], t, n, m, a[3010], siz[3010];
pair<int, long long> f[3010][3010], tmp[3010];
struct node {
  int nxt, to;
} star[3010 << 1];
inline void add(int from, int to) {
  wl++;
  star[wl].to = to;
  star[wl].nxt = head[from];
  head[from] = wl;
}
inline void chkmax(pair<int, long long> &a, pair<int, long long> b) {
  if (b > a) a = b;
}
inline void dfs(int x, int fa) {
  siz[x] = 1;
  f[x][1] = make_pair(0, a[x]);
  for (register int i = head[x]; i; i = star[i].nxt) {
    int u = star[i].to;
    if (u == fa) continue;
    dfs(u, x);
    for (register int j = 1; j <= siz[x] + siz[u]; ++j)
      tmp[j] = make_pair(-1, 0);
    for (register int j = 1; j <= siz[x]; ++j)
      for (register int k = 1; k <= siz[u]; ++k) {
        chkmax(tmp[j + k],
               make_pair(f[x][j].first + f[u][k].first + (f[x][j].second > 0),
                         f[x][k].second));
        chkmax(tmp[j + k - 1], make_pair(f[x][j].first + f[u][k].first,
                                         f[x][j].second + f[u][k].second));
      }
    for (register int j = 1; j <= siz[x] + siz[u]; ++j) f[x][j] = tmp[j];
    siz[x] += siz[u];
  }
}
int main() {
  t = rd();
  while (t--) {
    n = rd(), m = rd();
    for (register int i = 1; i <= n; ++i) a[i] -= rd();
    for (register int i = 1; i <= n; ++i) a[i] += rd();
    for (register int i = 1; i <= n - 1; ++i)
      x = rd(), y = rd(), add(x, y), add(y, x);
    dfs(1, 0);
    cout << f[1][m].first + (f[1][m].second > 0) << endl;
    wl = 0;
    for (register int i = 1; i <= n; ++i) head[i] = a[i] = 0;
  }
  return 0;
}
