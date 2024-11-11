#include <bits/stdc++.h>
using namespace std;
char v[110][11000];
int e[110][11000], d[110][11000], r[110][11000];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf(" %c", &v[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int tem = 0;
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == '1') {
        tem = 1;
        break;
      }
    }
    if (!tem) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 0; i <= n; i++) e[i][0] = -1;
  for (int i = 0; i <= m; i++) e[0][i] = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == '1')
        e[i][j] = 0;
      else if (e[i][j - 1] == -1)
        e[i][j] = -1;
      else
        e[i][j] = e[i][j - 1] + 1;
    }
  }
  for (int i = 0; i <= n; i++) d[i][m + 1] = -1;
  for (int i = 0; i <= m; i++) d[n + 1][i] = -1;
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (v[i][j] == '1')
        d[i][j] = 0;
      else if (d[i][j + 1] == -1)
        d[i][j] = -1;
      else
        d[i][j] = d[i][j + 1] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (e[i][j] == -1) e[i][j] = e[i][m] + i;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (d[i][j] == -1) d[i][j] = d[i][1] + m - j + 1;
    }
  }
  int res = n * m * 2;
  for (int j = 1; j <= m; j++) {
    int at = 0;
    for (int i = 1; i <= n; i++) {
      at += min(e[i][j], d[i][j]);
    }
    res = min(res, at);
  }
  if (res == n * m * 2)
    printf("-1\n");
  else
    printf("%d\n", res);
  return 0;
}
