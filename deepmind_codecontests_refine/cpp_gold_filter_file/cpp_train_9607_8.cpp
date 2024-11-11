#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int a[102][102];
int cnt;
int a1[20020], a2[20020], a3[20020], a4[20020], a5[20020], a6[20020];
char s[10020];
void move(int x, int y, int z, int w, int c, int b) {
  a[x][y] ^= 1;
  a[z][w] ^= 1;
  a[c][b] ^= 1;
  cnt++;
  a1[cnt] = x;
  a2[cnt] = y;
  a3[cnt] = z;
  a4[cnt] = w;
  a5[cnt] = c;
  a6[cnt] = b;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    cnt = 0;
    bool flag = 0;
    scanf("%d%d", &n, &m);
    if (n >= m) {
      for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) a[i][j] = s[j] - '0';
      }
    } else {
      flag = 1;
      for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) a[j][i] = s[j] - '0';
      }
      swap(n, m);
    }
    for (int i = 1; i < n; i++)
      for (int j = 1; j <= m; j += 2) {
        int y = (j == m) ? j - 1 : j + 1;
        if (a[i][j]) {
          if (a[i][y])
            move(i, j, i, y, i + 1, j);
          else
            move(i, j, i + 1, j, i + 1, y);
        } else if (a[i][y])
          move(i, y, i + 1, j, i + 1, y);
      }
    for (int j = 1; j <= m; j++) {
      int y = (j == m) ? j - 1 : j + 1;
      if (a[n][j] && a[n][y]) {
        move(n, j, n - 1, j, n - 1, y);
        move(n, y, n - 1, j, n - 1, y);
      } else {
        if (a[n][j]) {
          move(n, j, n, y, n - 1, j);
          move(n, j, n, y, n - 1, y);
          move(n, j, n - 1, j, n - 1, y);
        }
      }
    }
    if (cnt <= n * m) {
      printf("%d\n", cnt);
      for (int i = 1; i <= cnt; i++)
        if (!flag)
          printf("%d %d %d %d %d %d\n", a1[i], a2[i], a3[i], a4[i], a5[i],
                 a6[i]);
        else
          printf("%d %d %d %d %d %d\n", a2[i], a1[i], a4[i], a3[i], a6[i],
                 a5[i]);
    } else {
      for (int i = cnt; i >= 1; i--)
        if (!flag)
          move(a1[i], a2[i], a3[i], a4[i], a5[i], a6[i]);
        else
          move(a2[i], a1[i], a4[i], a3[i], a6[i], a5[i]);
      cnt = 0;
      for (int i = n; i > 1; i--)
        for (int j = 1; j <= m; j += 2) {
          int y = (j == m) ? j - 1 : j + 1;
          if (a[i][j]) {
            if (a[i][y])
              move(i, j, i, y, i - 1, y);
            else
              move(i, j, i - 1, j, i - 1, y);
          } else if (a[i][y])
            move(i, y, i - 1, j, i - 1, y);
        }
      for (int j = 1; j <= m; j++) {
        int y = (j == m) ? j - 1 : j + 1;
        if (a[1][j] && a[1][y]) {
          move(1, j, 2, j, 2, y);
          move(1, y, 2, j, 2, y);
        } else {
          if (a[1][j]) {
            move(1, j, 1, y, 2, j);
            move(1, j, 1, y, 2, y);
            move(1, j, 2, j, 2, y);
          }
        }
      }
      printf("%d\n", cnt);
      for (int i = 1; i <= cnt; i++)
        if (!flag)
          printf("%d %d %d %d %d %d\n", a1[i], a2[i], a3[i], a4[i], a5[i],
                 a6[i]);
        else
          printf("%d %d %d %d %d %d\n", a2[i], a1[i], a4[i], a3[i], a6[i],
                 a5[i]);
    }
  }
  return 0;
}
