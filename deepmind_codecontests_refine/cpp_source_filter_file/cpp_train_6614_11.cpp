#include <bits/stdc++.h>
int a[105][105];
struct node {
  int type;
  int r;
  int c;
  int x;
};
node s[10005];
int main() {
  int n, m, q, x;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &s[i].type);
    if (s[i].type == 1) scanf("%d", &s[i].r);
    if (s[i].type == 2) scanf("%d", &s[i].c);
    if (s[i].type == 3) scanf("%d%d%d", &s[i].r, &s[i].c, &s[i].x);
  }
  for (int i = q - 1; i >= 0; i--) {
    if (s[i].type == 3) a[s[i].r][s[i].c] = s[i].x;
    if (s[i].type == 1) {
      int o = s[i].r, u = a[o][m];
      for (int y = m; y > 1; y--) a[o][y] = a[o][y - 1];
      a[o][1] = u;
    }
    if (s[i].type == 2) {
      int o = s[i].c, u = a[n][o];
      for (int y = n; y > 1; y--) a[y][o] = a[y - 1][o];
      a[1][o] = u;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", a[i][j]);
    printf("\n");
  }
  return 0;
}
