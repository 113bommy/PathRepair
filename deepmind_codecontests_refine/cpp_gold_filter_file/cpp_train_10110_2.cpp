#include <bits/stdc++.h>
char f[100][100];
int c[100];
int main() {
  int n, m;
  double k;
  char s[30];
  int x, t = 0;
  int i, j;
  int flag = 0;
  scanf("%d %d %lf", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", s, &x);
    if (x * k + 0.001 >= 100) {
      t++;
      strcpy(f[t], s);
      c[t] = floor(x * k + 0.01);
    }
  }
  for (i = 1; i <= m; i++) {
    scanf("%s", s);
    for (j = 1, flag = 0; j <= t; j++) {
      if (strcmp(s, f[j]) == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      t++;
      strcpy(f[t], s);
    }
  }
  char ss[30];
  int xx;
  for (i = 1; i <= t; i++)
    for (j = i + 1; j <= t; j++) {
      if (strcmp(f[i], f[j]) > 0) {
        strcpy(ss, f[i]);
        strcpy(f[i], f[j]);
        strcpy(f[j], ss);
        xx = c[i];
        c[i] = c[j];
        c[j] = xx;
      }
    }
  printf("%d\n", t);
  for (i = 1; i <= t; i++) printf("%s %d\n", f[i], c[i]);
  return 0;
}
