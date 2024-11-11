#include <bits/stdc++.h>
using namespace std;
int i, n, m, X[120000], Y[120000], hang[3004][3004], lie[3004][3004],
    s[3004][3004], k, l, x, y, j, t;
int main() {
  scanf("%d", &n);
  for (k = 1; k <= n; ++k) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for (i = x1 + 1; i <= x2; ++i)
      for (j = y1 + 1; j <= y2; ++j) s[i][j]++;
    for (i = y1 + 1; i <= y2; ++i) hang[x1 + 1][i] = hang[x2 + 1][i] = 1;
    for (i = x1 + 1; i <= x2; ++i) lie[i][y1 + 1] = lie[i][y2 + 1] = 1;
    X[k] = x1 + 1;
    Y[k] = y1 + 1;
  }
  for (i = 1; i <= 3001; ++i)
    for (j = 1; j <= 3001; ++j) {
      hang[i][j] += hang[i][j - 1];
      lie[i][j] += lie[i - 1][j];
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  for (i = 1; i <= n; ++i) {
    x = X[i];
    y = Y[i];
    t = 1;
    for (;;) {
      if (s[x][y] - s[X[i] - 1][y] - s[x][Y[i] - 1] + s[X[i] - 1][Y[i] - 1] !=
          t * t)
        break;
      if (lie[x][Y[i]] - lie[x - 1][Y[i]] == 0) break;
      if (hang[X[i]][y] - hang[X[i]][y - 1] == 0) break;
      if (hang[x + 1][y] - hang[x + 1][Y[i] - 1] == t &&
          lie[x][y + 1] - lie[X[i] - 1][y + 1] == t) {
        int num = 0;
        for (j = 1; j <= n; ++j)
          if (X[j] >= X[i] && X[j] <= x && Y[j] >= Y[i] && Y[j] <= y) num++;
        printf("YES %d\n", num);
        for (j = 1; j <= n; ++j)
          if (X[j] >= X[i] && X[j] <= x && Y[j] >= Y[i] && Y[j] <= y)
            printf("%d ", j);
        return 0;
      }
      t++;
      x++;
      y++;
    }
  }
  printf("NO\n");
}
