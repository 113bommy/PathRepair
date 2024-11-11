#include <bits/stdc++.h>
using namespace std;
int n, m, q, ans;
int s[1010][1010];
int to[4][1010][1010];
int main() {
  int tp, x, y, up, L, R;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &s[i][j]);
  for (int i = m; i; i--)
    for (int j = 1; j <= n; j++) {
      if (!s[j][i])
        to[0][j][i] = 0;
      else
        to[0][j][i] = to[0][j][i + 1] + 1;
    }
  for (int i = n; i; i--)
    for (int j = 1; j <= m; j++) {
      if (!s[i][j])
        to[1][i][j] = 0;
      else
        to[1][i][j] = to[1][i + 1][j] + 1;
    }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      if (!s[j][i])
        to[2][j][i] = 0;
      else
        to[2][j][i] = to[2][j][i - 1] + 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (!s[i][j])
        to[3][i][j] = 0;
      else
        to[3][i][j] = to[3][i - 1][j] + 1;
    }
  while (q--) {
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1) {
      s[x][y] ^= 1;
      if (!s[x][y]) {
        for (int i = y; i; i--) to[0][x][i] = min(to[0][x][i], y - i);
        for (int i = x; i; i--) to[1][i][y] = min(to[1][i][y], x - i);
        for (int i = y; i <= m; i++) to[2][x][i] = min(to[2][x][i], i - y);
        for (int i = x; i <= n; i++) to[3][i][y] = min(to[3][i][y], i - x);
      } else {
        for (int i = y; i && s[x][i]; i--) to[0][x][i] += to[0][x][y + 1] + 1;
        for (int i = x; i && s[i][y]; i--) to[1][i][y] += to[1][x + 1][y] + 1;
        for (int i = y; i <= m && s[x][i]; i++)
          to[2][x][i] += to[2][x][y - 1] + 1;
        for (int i = x; i <= n && s[i][y]; i++)
          to[3][i][y] += to[3][x - 1][y] + 1;
      }
    } else {
      if (!s[x][y]) {
        puts("0");
        continue;
      }
      ans = 1;
      L = R = x;
      up = to[0][x][y];
      while (up) {
        while (L > 1 && to[0][L - 1][y] >= up) L--;
        while (R < n && to[0][R + 1][y] >= up) R++;
        ans = max(ans, up * (R - L + 1));
        up--;
      }
      L = R = y;
      up = to[1][x][y];
      while (up) {
        while (L > 1 && to[1][x][L - 1] >= up) L--;
        while (R < m && to[1][x][R + 1] >= up) R++;
        ans = max(ans, up * (R - L + 1));
        up--;
      }
      L = R = x;
      up = to[2][x][y];
      while (up) {
        while (L > 1 && to[2][L - 1][y] >= up) L--;
        while (R < n && to[2][R + 1][y] >= up) R++;
        ans = max(ans, up * (R - L + 1));
        up--;
      }
      L = R = y;
      up = to[3][x][y];
      while (up) {
        while (L > 1 && to[3][x][L - 1] >= up) L--;
        while (R < m && to[3][x][R + 1] >= up) R++;
        ans = max(ans, up * (R - L + 1));
        up--;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
