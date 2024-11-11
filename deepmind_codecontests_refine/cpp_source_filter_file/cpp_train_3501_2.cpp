#include <bits/stdc++.h>
int main() {
  int m, n, l[100], r[100], i, j;
  char s[100], c1[100], c2[100];
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  for (i = 0; i < m; i++) {
    scanf("%d", &l[i]);
    scanf("%d", &r[i]);
    scanf("%s", &c1[i]);
    scanf("%s", &c2[i]);
  }
  for (i = 0; i < m; i++) {
    for (j = l[i] - 1; j <= r[i]; j++) {
      if (c1[i] == s[j]) {
        s[j] = c2[i];
      }
    }
  }
  printf("%s", s);
}
