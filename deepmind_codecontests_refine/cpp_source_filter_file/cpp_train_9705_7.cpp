#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const char *alpha = "RGYB";
int n, m, q, st[maxn][maxn][9][9], sum[4][maxn][maxn], mm[maxn];
char s[maxn][maxn];
inline bool get(int t, int x, int y, int l) {
  return l * l == sum[t][x][y] - sum[t][x - l][y] - sum[t][x][y - l] +
                      sum[t][x - l][y - l];
}
inline int get(int x, int y) {
  int left = 0, right = min(min(x, n - x), min(y, m - y)), res = 0;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (get(0, x, y, mid) && get(1, x, y + mid, mid) &&
        get(2, x + mid, y, mid) + get(3, x + mid, y + mid, mid)) {
      res = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  return res;
}
inline void init() {
  mm[0] = -1;
  for (int i = 1; i < maxn; ++i) mm[i] = mm[i - 1] + !(i & (i - 1));
  for (int a = 0; a <= mm[n]; ++a)
    for (int b = 0; b <= mm[m]; ++b)
      if (a + b)
        for (int i = 1; i + (1 << a) - 1 <= n; ++i)
          for (int j = 1; j + (1 << b) - 1 <= m; ++j)
            if (!a)
              st[i][j][a][b] =
                  max(st[i][j][a][b - 1], st[i][j + (1 << (b - 1))][a][b - 1]);
            else
              st[i][j][a][b] =
                  max(st[i][j][a - 1][b], st[i + (1 << (a - 1))][j][a - 1][b]);
}
inline int query(int l, int r, int u, int d) {
  int a = mm[r - l + 1], b = mm[d - u + 1];
  return max(max(st[l][u][a][b], st[r - (1 << a) + 1][u][a][b]),
             max(st[l][d - (1 << b) + 1][a][b],
                 st[r - (1 << a) + 1][d - (1 << b) + 1][a][b]));
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int k = 0; k < 4; ++k)
        sum[k][i][j] = (s[i][j] == alpha[k]) + sum[k][i - 1][j] +
                       sum[k][i][j - 1] - sum[k][i - 1][j - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) st[i][j][0][0] = get(i, j);
  init();
  while (q--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int left = 1, right = min(c - a + 1, d - b + 1) / 2, res = 0;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (query(a + mid - 1, c - mid, b + mid - 1, d - mid) >= mid) {
        res = mid;
        left = mid + 1;
      } else
        right = mid - 1;
    }
    printf("%d\n", 4 * res * res);
  }
  return 0;
}
