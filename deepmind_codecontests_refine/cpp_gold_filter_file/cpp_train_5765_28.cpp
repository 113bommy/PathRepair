#include <bits/stdc++.h>
int N, M;
double e[1000][1000];
int main() {
  scanf("%d%d", &N, &M);
  int x, y;
  scanf("%d%d", &x, &y);
  if (x == N) {
    printf("%.5f\n", 0.0);
    return 0;
  }
  int loop_max = 100000000 / M / (N - x);
  for (int i = 0; i < (int)(N); i++)
    for (int j = 0; j < (int)(M); j++) e[i][j] = 0.0;
  for (int i = N - 2; i >= x - 1; i--) {
    for (int q = 0; q < (int)(loop_max); q++) {
      for (int j = 0; j < (int)(M); j++) {
        double s = 0.0;
        int c = 0;
        s += e[i][j] + 1;
        c++;
        s += e[i + 1][j] + 1;
        c++;
        if (j > 0) {
          s += e[i][j - 1] + 1;
          c++;
        }
        if (j < M - 1) {
          s += e[i][j + 1] + 1;
          c++;
        }
        e[i][j] = s / c;
      }
    }
  }
  printf("%.5f\n", e[x - 1][y - 1]);
  return 0;
}
