#include <bits/stdc++.h>
char v[110][110], s[110];
char sres[110];
int vt[110];
int c[110];
char let;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %s", v[i]);
    vt[i] = strlen(v[i]);
    for (int j = 0; j < vt[i]; j++) v[i][j] = v[i][j] & (~32);
  }
  scanf(" %s %c", s, &let);
  int st = strlen(s);
  for (int i = 0; i < st; i++) {
    c[i] = s[i] & 32;
    s[i] = s[i] & (~32);
  }
  let = let & (~32);
  strcpy(sres, s);
  for (int i = 0; i < st; i++) {
    for (int j = 0; j < n; j++)
      if (strncmp(s + i, v[j], vt[j]) == 0) {
        for (int k = 0; k < vt[j]; k++) {
          if (s[i + k] == let) {
            if (let == 'A')
              sres[i + k] = 'A';
            else
              sres[i + k] = 'B';
          } else
            sres[i + k] = let;
        }
      }
  }
  for (int i = 0; i < st; i++) sres[i] = sres[i] | c[i];
  printf("%s\n", sres);
}
