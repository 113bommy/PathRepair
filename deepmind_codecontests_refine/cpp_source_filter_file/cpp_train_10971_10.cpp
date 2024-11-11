#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int main(void) {
  int b, d, pos[26][100], next[100], qta[100], la, lc, j, i, k, ans, ii,
      qtc[100];
  char a[101], c[101], cc;
  scanf("%d%d", &b, &d);
  scanf("%s%s", a, c);
  la = strlen(a);
  lc = strlen(c);
  for (i = 0; i < 26; i++) {
    cc = 'a' + i;
    for (j = 0; j < la; j++) {
      for (k = j; k < la && a[k] != cc; k++)
        ;
      pos[i][j] = k;
    }
  }
  for (i = 0; i < la; i++) {
    k = i;
    qta[i] = 0;
    qtc[i] = 0;
    while (!qta[i]) {
      for (j = 0; j < lc; j++) {
        ii = c[j] - 'a';
        k = pos[ii][k];
        if (k == la) {
          k = pos[ii][0];
          qta[i]++;
          if (k == la) {
            printf("0\n");
            return 0;
          }
        }
        k = (k + 1) % la;
        if (!k) qta[i]++;
      }
      qtc[i]++;
      next[i] = k;
    }
  }
  ans = 0;
  i = 1;
  k = 0;
  while (i <= b) {
    i += qta[k];
    ans += qtc[k];
    k = next[k];
  }
  if (i > b) ans--;
  printf("%d\n", ans / d);
  return 0;
}
