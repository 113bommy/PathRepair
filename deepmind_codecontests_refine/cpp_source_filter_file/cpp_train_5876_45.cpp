#include <bits/stdc++.h>
int main() {
  int i, j, n = 0, x = 0;
  char s[100], c[100], p[100];
  scanf("%s", s);
  scanf("%s", c);
  n = strlen(s);
  for (i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
    if (s[i] != c[j]) {
      x = 1;
      break;
    }
  }
  if (x == 1)
    printf("NO");
  else
    printf("YES");
  return 0;
}
