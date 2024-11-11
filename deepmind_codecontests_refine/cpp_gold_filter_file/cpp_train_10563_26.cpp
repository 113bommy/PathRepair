#include <bits/stdc++.h>
int main() {
  int n, m, i, j;
  scanf("%d %d", &n, &m);
  char s[m + 1][15];
  char s1[m + 1][15];
  char s2[15];
  for (i = 0; i < m; i++) {
    scanf("%s", s[i]);
    scanf("%s", s1[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%s", s2);
    for (j = 0; j < m; j++) {
      if (strcmp(s2, s[j]) == 0) {
        if (strlen(s1[j]) < strlen(s[j]))
          printf("%s ", s1[j]);
        else
          printf("%s ", s[j]);
      }
    }
  }
}
