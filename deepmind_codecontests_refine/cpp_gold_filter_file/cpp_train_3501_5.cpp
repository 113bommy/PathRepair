#include <bits/stdc++.h>
int main() {
  int m, n, l[101], r[101], i, j;
  char s[101], c1[101], c2[101];
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  for (i = 0; i < m; i++) {
    scanf("%d", &l[i]);
    scanf("%d", &r[i]);
    scanf("%s", &c1[i]);
    scanf("%s", &c2[i]);
  }
  for (i = 0; i < m; i++) {
    for (j = l[i] - 1; j < r[i]; j++) {
      if (c1[i] == s[j]) {
        s[j] = c2[i];
      }
    }
  }
  printf("%s", s);
}
