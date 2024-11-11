#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * t;
}
const int N = 2005;
const int M = 1e5 + 5;
const long long Inf = (1ll << 60);
int n, m, S, T, tA, tB, cnt, w[N], vis[N], H[N];
long long d[2][N], a[N], b[N], s[2][N][N], f[2][N][N][2];
bool h[2][N][N], g[2][N][N][2];
struct edge {
  int to, nxt, v;
} e[M * 2];
void Add(int x, int y, int v) {
  e[++cnt] = (edge){y, H[x], v};
  H[x] = cnt;
  e[++cnt] = (edge){x, H[y], v};
  H[y] = cnt;
}
void Dij(int S, long long *d) {
  for (int i = 1; i <= n; i++) d[i] = Inf, vis[i] = 0;
  d[S] = 0;
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && (!x || d[j] < d[x])) x = j;
    vis[x] = 1;
    for (int i = H[x]; i; i = e[i].nxt) {
      int y = e[i].to;
      d[y] = min(d[y], d[x] + e[i].v);
    }
  }
}
long long DP(int t, int x, int y, int v) {
  if ((!t && x > tA) || (t && x > tB)) return 0;
  if (g[t][x][y][v]) return f[t][x][y][v];
  long long res = !t ? -Inf : Inf;
  if (!t) {
    if (v) res = max(res, DP(1, y, x, 0));
    res = max(res, DP(0, x + 1, y, v | h[0][x + 1][y]) + s[0][x + 1][y]);
  } else {
    if (v) res = min(res, DP(0, y, x, 0));
    res = min(res, DP(1, x + 1, y, v | h[1][x + 1][y]) - s[1][x + 1][y]);
  }
  return g[t][x][y][v] = 1, f[t][x][y][v] = res;
}
int main() {
  n = read(), m = read(), S = read(), T = read();
  for (int i = 1; i <= n; i++) w[i] = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), v = read();
    Add(x, y, v);
  }
  Dij(S, d[0]), Dij(T, d[1]);
  for (int i = 1; i <= n; i++) a[i] = d[0][i];
  sort(a + 1, a + n + 1), tA = unique(a + 1, a + n + 1) - a - 1;
  for (int i = 1; i <= n; i++) b[i] = d[1][i];
  sort(b + 1, b + n + 1), tB = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(a + 1, a + tA + 1, d[0][i]) - a;
    int y = lower_bound(b + 1, b + tB + 1, d[1][i]) - b;
    s[0][x][y - 1] += w[i], h[0][x][y - 1] = 1;
    s[1][y][x - 1] += w[i], h[1][y][x - 1] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = n; j >= 0; j--)
      for (int t = 0; t <= 1; t++) {
        s[t][i][j] += s[t][i][j + 1];
        h[t][i][j] |= h[t][i][j + 1];
      }
  long long res = DP(0, 0, 0, 0);
  if (res < 0)
    puts("Cry");
  else if (res > 0)
    puts("Break a heart");
  else
    puts("Flowers");
  return 0;
}
