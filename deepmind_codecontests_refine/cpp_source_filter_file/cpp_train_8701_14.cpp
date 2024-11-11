#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) sum = sum * 10 + (ch ^ 48), ch = getchar();
  return sum * ff;
}
int n, m, p, k, la[505], lb[505], f[2][1001][51][51], ans;
int main() {
  n = read();
  p = read();
  k = read();
  int a = read();
  for (int i = 1; i <= a; i++) la[read()] = 1;
  int b = read();
  for (int i = 1; i <= b; i++) lb[read()] = 1;
  if (p * k >= n * 2) {
    ans = 0;
    for (int i = 1; i <= n; i++) ans += (la[i] | lb[i]);
    printf("%d\n", ans);
    return 0;
  }
  memset(f, -127 / 3, sizeof(f));
  int op = 1, las = 0;
  f[0][0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    las = (i + 1) % 2;
    op = i % 2;
    memset(f[op], -127 / 3, sizeof(f[op]));
    for (int j = 0; j <= p; j++)
      for (int x = 0; x <= k; x++)
        for (int y = 0; y <= k; y++) {
          int ls = f[las][j][x][y];
          f[op][j][max(0, x - 1)][max(0, y - 1)] =
              max(f[op][j][max(0, x - 1)][max(0, y - 1)], ls);
          if (x)
            f[op][j][x - 1][max(0, y - 1)] =
                max(f[op][j][x - 1][max(0, y - 1)], ls + la[i]);
          if (x)
            f[op][j + 1][x - 1][k - 1] =
                max(f[op][j + 1][x - 1][k - 1], ls + (la[i] | lb[i]));
          if (y)
            f[op][j][max(0, x - 1)][y - 1] =
                max(f[op][j][max(0, x - 1)][y - 1], ls + lb[i]);
          if (y)
            f[op][j + 1][k - 1][y - 1] =
                max(f[op][j + 1][k - 1][y - 1], ls + (la[i] | lb[i]));
          if (x && y)
            f[op][j][x - 1][y - 1] =
                max(f[op][j][x - 1][y - 1], ls + (la[i] | lb[i]));
          f[op][j + 2][k - 1][k - 1] =
              max(f[op][j + 2][k - 1][k - 1], ls + (la[i] | lb[i]));
          f[op][j + 1][k - 1][max(y - 1, 0)] =
              max(f[op][j + 1][k - 1][max(y - 1, 0)], ls + la[i]);
          f[op][j + 1][max(x - 1, 0)][k - 1] =
              max(f[op][j + 1][max(x - 1, 0)][k - 1], ls + lb[i]);
        }
  }
  for (int i = 0; i <= p; i++)
    for (int j = 0; j <= k; j++)
      for (int x = 0; x <= k; x++) ans = max(ans, f[n & 1][i][j][x]);
  printf("%d\n", ans);
  return 0;
}
