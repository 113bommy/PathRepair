#include <bits/stdc++.h>
char x, y;
long i, j, k, l, n, m, ans, q, min;
long ar[255][255];
char s1[100009], s2[100009];
int main() {
  scanf("%s\n", &s1);
  scanf("%s\n", &s2);
  scanf("%d", &n);
  for (i = 'a'; i <= 'z'; i++)
    for (j = 'a'; j <= 'z'; j++)
      if (i == j)
        ar[i][j] = 0;
      else
        ar[i][j] = 999999;
  for (i = 1; i <= n; i++) {
    scanf("\n %c %c %d", &x, &y, &q);
    if (ar[x][y] > q) ar[x][y] = q;
  }
  for (l = 'a'; l <= 'z'; l++)
    for (i = 'a'; i <= 'z'; i++) {
      for (j = 'a'; j <= 'z'; j++) {
        if (ar[i][l] != 999999 && ar[l][j] != 999999 &&
            ar[i][j] > ar[i][l] + ar[l][j])
          ar[i][j] = ar[i][l] + ar[l][j];
      }
    }
  n = strlen(s1);
  m = strlen(s2);
  if (n != m) {
    printf("-1");
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      min = 999999;
      for (j = 'a'; j <= 'z'; j++) {
        if (ar[s1[i]][j] != 999999 && ar[s2[i]][j] != 999999 &&
            min > ar[s1[i]][j] + ar[s2[i]][j]) {
          min = ar[s1[i]][j] + ar[s2[i]][j];
          x = j;
        }
      }
      if (min == 999999) {
        printf("-1");
        return 0;
      }
      ans += min;
      s2[i] = x;
    }
  }
  printf("%d\n", ans);
  printf("%s", s2);
  return 0;
}
