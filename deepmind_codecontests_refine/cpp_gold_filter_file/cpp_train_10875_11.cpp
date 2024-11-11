#include <bits/stdc++.h>
int mat[50][50], n, m;
int Founc(int x, int y, int a, int b) {
  int i, j, count, c, d, f, g, min;
  min = 99999999;
  for (i = x; i < n; i++)
    for (j = y; j < m; j++) {
      count = 0;
      c = i + a - 1;
      d = j + b - 1;
      if (c < n && d < m) {
        for (f = i; f <= c; f++)
          for (g = j; g <= d; g++)
            if (mat[f][g] == 1) count++;
        if (count < min) min = count;
      } else
        continue;
    }
  return min;
}
int main() {
  int i, j, a, b;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) scanf("%d", &mat[i][j]);
    scanf("%d%d", &a, &b);
    i = Founc(0, 0, a, b);
    j = Founc(0, 0, b, a);
    printf("%d\n", i > j ? j : i);
  }
  return 0;
}
