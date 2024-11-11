#include <bits/stdc++.h>
int main() {
  char s[101], t[101];
  int m, n, i, j, f = 1;
  scanf("%s", s);
  scanf("%s", t);
  m = strlen(s);
  n = strlen(t);
  if (m == n) {
    for (i = 0, j = n - 1; i < m; i++, j--)
      if (s[i] != t[j]) {
        f = 0;
        break;
      }
    if (f == 1)
      printf("YES");
    else
      printf("NO");
  } else
    printf("NO");
}
