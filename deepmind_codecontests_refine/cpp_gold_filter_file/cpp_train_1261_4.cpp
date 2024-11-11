#include <bits/stdc++.h>
char map[1050][1050];
int left[1050][1050], right[1050][1050], up[1050][1050], down[1050][1050];
int a[105000], b[105000];
int main(void) {
  int i, n, m, k, j, x, y, xx, yy, tot = 0;
  char s[20], ans[100], ch;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", map[i] + 1);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (map[i][j] != '#') {
        if (j > 1 && map[i][j - 1] != '#') left[i][j] = left[i][j - 1] + 1;
        if (i > 1 && map[i - 1][j] != '#') up[i][j] = up[i - 1][j] + 1;
      }
  for (i = n; i >= 1; i--)
    for (j = m; j >= 1; j--) {
      if (map[i][j] != '#') {
        if (j < m && map[i][j + 1] != '#') right[i][j] = right[i][j + 1] + 1;
        if (i < n && map[i + 1][j] != '#') down[i][j] = down[i + 1][j] + 1;
      }
    }
  scanf("%d", &k);
  for (i = 1; i <= k; i++) {
    scanf("%s%d", s, &b[i]);
    if (s[0] == 'N')
      a[i] = 1;
    else if (s[0] == 'S')
      a[i] = 2;
    else if (s[0] == 'W')
      a[i] = 3;
    else
      a[i] = 4;
  }
  for (x = 1; x <= n; x++)
    for (y = 1; y <= m; y++)
      if (map[x][y] >= 'A' && map[x][y] <= 'Z') {
        xx = x;
        yy = y;
        for (i = 1; i <= k; i++) {
          if (a[i] == 1) {
            if (up[xx][yy] >= b[i])
              xx -= b[i];
            else
              break;
          }
          if (a[i] == 2) {
            if (down[xx][yy] >= b[i])
              xx += b[i];
            else
              break;
          }
          if (a[i] == 3) {
            if (left[xx][yy] >= b[i])
              yy -= b[i];
            else
              break;
          }
          if (a[i] == 4) {
            if (right[xx][yy] >= b[i])
              yy += b[i];
            else
              break;
          }
        }
        if (i == k + 1) ans[tot++] = map[x][y];
      }
  if (tot == 0)
    printf("no solution\n");
  else {
    ans[tot] = 0;
    for (i = 0; i < tot; i++)
      for (j = i + 1; j < tot; j++)
        if (ans[i] > ans[j]) {
          ch = ans[i];
          ans[i] = ans[j];
          ans[j] = ch;
        }
    printf("%s\n", ans);
  }
  return 0;
}
