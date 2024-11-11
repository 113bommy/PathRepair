#include <bits/stdc++.h>
int n, m, i, j, w, ans, tmp;
int s[101][10001];
char ch[101][10001];
int abs(int x) {
  if (x < 0) return (-x);
  return x;
}
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", &ch[i]);
  ans = 10000000;
  for (i = 1; i <= n; i++) {
    w = 0;
    for (j = 0; j <= m - 1; j++) s[i][j] = 10000000;
    for (j = 0; j <= m - 1; j++)
      if (ch[i][j] == '1') w++;
    if (w != 0) {
      for (j = 0; j <= m - 1; j++)
        if (ch[i][j] == '1') break;
      w = j;
      for (j = m - 1; j >= 0; j--) {
        w++;
        if (ch[i][j] == '1') w = 0;
        s[i][j] = min(s[i][j], w);
      }
      for (j = m - 1; j >= 0; j--)
        if (ch[i][j] == '1') break;
      w = m - 1 - j;
      for (j = 0; j <= m - 1; j++) {
        w++;
        if (ch[i][j] == '1') w = 0;
        s[i][j] = min(s[i][j], w);
      }
    }
  }
  for (i = 0; i <= m - 1; i++) {
    tmp = 0;
    for (j = 1; j <= n; j++) tmp = tmp + s[j][i];
    if (tmp < ans) ans = tmp;
  }
  if (ans != 10000000)
    printf("%d\n", ans);
  else
    printf("-1\n");
  scanf("\n");
}
