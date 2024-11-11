#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 3e5 + 10;
int n, a[maxn];
int log[maxn];
int l[20][maxn], r[20][maxn];
struct RMQ {
  int st[maxn][20], val[maxn];
  int op;
  inline int MAX(int x, int y) { return val[x] > val[y] ? x : y; }
  inline void build(int *b, int n, int _op) {
    op = _op;
    for (int i = 1; i <= n; i++) st[i][0] = i, val[i] = op * b[i];
    for (int j = 1; j <= log[n]; j++)
      for (int i = 1; i <= n; i++)
        st[i][j] = MAX(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }
  inline int query(int l, int r) {
    int k = log[r - l + 1];
    return MAX(st[l][k], st[r - (1 << k) + 1][k]);
  }
} L, R;
inline void work() {
  n = read();
  if (n == 1) return (void)puts("0");
  for (int i = 2; i <= 3 * n; i++) log[i] = log[i >> 1] + 1;
  for (int i = 1; i <= n; i++) a[i] = a[i + n] = a[i + n + n] = read();
  for (int i = 0; i <= log[3 * n]; i++) l[i][1] = 1, r[i][n * 3] = 3 * n;
  for (int i = 1; i <= 3 * n; i++)
    l[0][i] = max(1, i - a[i]), r[0][i] = min(n * 3, i + a[i]);
  L.build(l[0], 3 * n, -1), R.build(r[0], 3 * n, 1);
  for (int l1, r1, j = 1; j <= log[3 * n]; j++)
    for (int i = 1; i <= 3 * n; i++) {
      l1 = L.query(l[j - 1][i], r[j - 1][i]);
      r1 = R.query(r[j - 1][i], r[j - 1][i]);
      l[j][i] = min(l[j - 1][l1], l[j - 1][r1]);
      r[j][i] = max(r[j - 1][l1], r[j - 1][r1]);
    }
  for (int i = n + 1; i <= n << 1; i++) {
    int u = i, v = i, ans = 0;
    for (int j = log[n * 3]; ~j; j--)
      if (max(r[j][u], r[j][v]) - min(l[j][u], l[j][v]) + 1 < n) {
        int su = L.query(l[j][u], r[j][v]), sv = R.query(l[j][u], r[j][v]);
        u = su, v = sv;
        ans += (1 << j);
      }
    printf("%d ", ans + 1);
  }
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
