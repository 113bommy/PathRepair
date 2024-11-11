#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int M = 100005;
int X[M], Y[M], n;
int sum[N][N];
int f1[N][N];
int f2[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x1, x2, wzpakking, y2;
    scanf("%d%d%d%d", &x1, &wzpakking, &x2, &y2);
    for (int x = x1 + 1; x <= x2; x++)
      for (int y = wzpakking + 1; y <= y2; y++) sum[x][y]++;
    for (int x = x1 + 1; x <= x2; x++) f2[x][wzpakking + 1] = f2[x][y2 + 1] = 1;
    for (int y = wzpakking + 1; y <= y2; y++) f1[x1 + 1][y] = f1[x2 + 1][y] = 1;
    X[i] = x1 + 1;
    Y[i] = wzpakking + 1;
  }
  for (int i = 1; i <= 3001; i++)
    for (int j = 1; j <= 3001; j++)
      sum[i][j] += sum[i][j - 1], f1[i][j] += f1[i][j - 1];
  for (int i = 1; i <= 3001; i++)
    for (int j = 1; j <= 3001; j++)
      sum[i][j] += sum[i - 1][j], f2[i][j] += f2[i - 1][j];
  for (int i = 1; i <= n; i++) {
    int x = X[i], y = Y[i], t = 1;
    for (;;) {
      if (sum[x][y] - sum[X[i] - 1][y] - sum[x][Y[i] - 1] +
              sum[X[i] - 1][Y[i] - 1] !=
          t * t)
        break;
      if (f1[X[i]][y] == f1[X[i]][y - 1]) break;
      if (f2[x][Y[i]] == f2[x - 1][Y[i]]) break;
      if (f1[x + 1][y] - f1[x + 1][Y[i] - 1] == t)
        if (f2[x][y + 1] - f2[X[i] - 1][y + 1] == t) {
          int tot = 0;
          for (int j = 1; j <= n; j++)
            if (X[i] <= X[j] && X[j] <= x)
              if (Y[i] <= Y[j] && Y[j] <= x) tot++;
          printf("YES %d\n", tot);
          for (int j = 1; j <= n; j++)
            if (X[i] <= X[j] && X[j] <= x)
              if (Y[i] <= Y[j] && Y[j] <= x) printf("%d ", j);
          exit(0);
        }
      x++;
      y++;
      t++;
    }
  }
  puts("NO");
}
