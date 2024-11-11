#include <bits/stdc++.h>
int a[1001][1001];
int main(void) {
  int m, n;
  while (scanf("%d%d", &n, &m) != EOF) {
    int i, j, b[1001][2], c = 1, d[1002], e;
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    for (i = 0; i < m; i++) {
      scanf("%d%d", &b[i][0], &b[i][1]);
      a[c][b[i][0]] = 1;
      a[c][b[i][1]] = 1;
      c++;
      d[b[i][0]]++;
      d[b[i][1]]++;
    }
    for (i = 1; i <= n; i++) {
      if (d[i] == 0) {
        d[i] = 1;
        a[c][d[i]] = 1;
        c++;
      }
      printf("%d\n", d[i]);
      for (j = 1; j < c; j++) {
        if (a[j][i] == 1) printf("%d %d\n", j, i);
      }
    }
    printf("\n");
  }
  return 0;
}
