#include <bits/stdc++.h>
const int maxline = 100001;
int main() {
  char str;
  int n, m, q, i, j, k;
  int s[maxline], t[maxline], a, b, c, d;
  int f[2][maxline], g[2][maxline];
  str = getchar();
  n = 0;
  int sum = 0;
  f[0][0] = 0;
  g[0][0] = 0;
  while (str == 'A' || str == 'B' || str == 'C') {
    n++;
    if (str == 'A') {
      s[n] = 0;
      sum++;
      f[0][n] = f[0][n - 1];
      g[0][n] = sum;
    } else {
      s[n] = 1;
      sum = 0;
      f[0][n] = f[0][n - 1] + 1;
      g[0][n] = sum;
    }
    str = getchar();
  }
  while (str != 'A' && str != 'B' && str != 'C') str = getchar();
  m = 0;
  sum = 0;
  f[1][0] = 0;
  g[1][0] = 0;
  while (str == 'A' || str == 'B' || str == 'C') {
    m++;
    if (str == 'A') {
      t[m] = 0;
      sum++;
      f[1][m] = f[1][m - 1];
      g[1][m] = sum;
    } else {
      t[m] = 1;
      sum = 0;
      f[1][m] = f[1][m - 1] + 1;
      g[1][m] = sum;
    }
    str = getchar();
  }
  scanf("%d", &q);
  int answer[maxline];
  for (i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    answer[i] = 0;
    int e = (f[1][d] - f[1][c - 1]) - (f[0][b] - f[0][a - 1]);
    int es, et, ok1 = 1, ok2 = 1;
    if (f[0][b] - f[0][a - 1] > 0)
      es = g[0][b];
    else {
      es = b - a + 1;
      ok1 = 0;
    }
    if (f[1][d] - f[1][c - 1] > 0)
      et = g[1][d];
    else {
      et = d - c + 1;
      ok2 = 0;
    }
    if (!(ok1 == 0 && ok2 == 1) || es - et > 0)
      if (e >= 0 && e % 2 == 0 && es - et >= 0) {
        if (e > 0)
          answer[i] = 1;
        else if ((es - et) % 3 == 0)
          answer[i] = 1;
      }
  }
  for (i = 1; i <= q; i++) printf("%d", answer[i]);
  printf("\n");
}
