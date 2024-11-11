#include <bits/stdc++.h>
using namespace std;
int n, m, q, h[1001][1001], v[1001][1001];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i < n + 1; ++i)
    for (int j = 1; j < m + 1; ++j) {
      int t;
      scanf("%d", &t);
      h[i][j] = t + h[i][j - 1];
      v[j][i] = t + v[j][i - 1];
    }
  while (q--) {
    int o, x, y;
    scanf("%d%d%d", &o, &x, &y);
    if (o == 1) {
      int d = h[x][y] - h[x][y - 1];
      if (d)
        d = -1;
      else
        d = 1;
      for (int i = x; i < n + 1; ++i) v[y][i] += d;
      for (int i = y; i < m + 1; ++i) h[x][i] += d;
    } else {
      if (h[x][y] == h[x][y - 1]) {
        printf("0\n");
        continue;
      }
      int l = y, r = y, u = x, d = x, an = 0;
      while (r <= n && h[x][r] > h[x][r - 1]) ++r;
      --r;
      while (l > 0 && h[x][l] > h[x][l - 1]) --l;
      ++l;
      while (u > 0 && v[y][u] > v[y][u - 1]) --u;
      ++u;
      while (d <= n && v[y][d] > v[y][d - 1]) ++d;
      --d;
      an = max(r - l + 1, d - u + 1);
      int lt = l, rt = r, ut = u, dt = d;
      int j = y + 1;
      while (j <= m) {
        while (u < n && v[j][x] - v[j][u - 1] != x - u + 1) ++u;
        while (d >= 1 && v[j][d] - v[j][x - 1] != d - x + 1) --d;
        if (d < u) break;
        an = max(an, (j - y + 1) * (d - u + 1));
        ++j;
      }
      int i = x + 1;
      while (i <= n) {
        while (l < m && h[i][y] - h[i][l - 1] != y - l + 1) ++l;
        while (r >= 1 && h[i][r] - h[i][y - 1] != r - y + 1) --r;
        if (r < l) break;
        an = max(an, (i - x + 1) * (r - l + 1));
        ++i;
      }
      l = lt, r = rt, u = ut, d = dt;
      j = y - 1;
      while (j > 0) {
        while (u < n && v[j][x] - v[j][u - 1] != x - u + 1) ++u;
        while (d >= 1 && v[j][d] - v[j][x - 1] != d - x + 1) --d;
        if (d < u) break;
        an = max(an, (y - j + 1) * (d - u + 1));
        --j;
      }
      i = x - 1;
      while (i > 0) {
        while (l < m && h[i][y] - h[i][l - 1] != y - l + 1) ++l;
        while (r >= 1 && h[i][r] - h[i][y - 1] != r - y + 1) --r;
        if (r < l) break;
        an = max(an, (x - i + 1) * (r - l + 1));
        --i;
      }
      printf("%d\n", an);
    }
  }
}
