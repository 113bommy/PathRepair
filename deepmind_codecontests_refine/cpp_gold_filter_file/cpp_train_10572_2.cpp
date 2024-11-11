#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1100;
const int MAXB = 10;
int s[MAXN][MAXN];
short p[MAXB][MAXB][MAXN][MAXN];
int lg[MAXN];
inline int read() {
  int x = 0;
  char ch = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x;
}
inline int query(int l, int d, int r, int u) {
  int x = lg[r - l + 1], y = lg[u - d + 1];
  return max(max(p[x][y][l][d], p[x][y][r - (1 << x) + 1][u - (1 << y) + 1]),
             max(p[x][y][r - (1 << x) + 1][d], p[x][y][l][u - (1 << y) + 1]));
}
int main() {
  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + (read() ^ 1);
      int l = 0, r = min(i, j);
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (s[i][j] - s[i - mid][j] - s[i][j - mid] + s[i - mid][j - mid])
          r = mid - 1;
        else
          l = mid;
      }
      p[0][0][i][j] = l;
    }
  for (int i = 1, l = 0; i <= n || i <= m; i++) lg[i] = l += 1 << l + 1 <= i;
  for (int k = 1; 1 << k <= n; k++)
    for (int i = 1; i + (1 << k) - 1 <= n; i++)
      for (int j = 1; j <= m; j++)
        p[k][0][i][j] =
            max(p[k - 1][0][i][j], p[k - 1][0][i + (1 << k - 1)][j]);
  for (int x = 0; 1 << x <= n; x++)
    for (int y = 1; 1 << y <= m; y++)
      for (int i = 1; i + (1 << x) - 1 <= n; i++)
        for (int j = 1; j + (1 << y) - 1 <= m; j++)
          p[x][y][i][j] =
              max(p[x][y - 1][i][j], p[x][y - 1][i][j + (1 << y - 1)]);
  scanf("%d", &q);
  while (q--) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1);
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (query(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid)
        l = mid;
      else
        r = mid - 1;
    }
    printf("%d\n", l);
  }
  return 0;
}
