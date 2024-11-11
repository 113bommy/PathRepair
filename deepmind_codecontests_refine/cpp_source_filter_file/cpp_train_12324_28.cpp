#include <bits/stdc++.h>
int main() {
  int a = 0, i, n;
  char x, tab[150];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", &tab);
    if (strcmp(tab, "x++") == 0 || strcmp(tab, "++x") == 0)
      a = a + 1;
    else if (strcmp(tab, "x--") == 0 || strcmp(tab, "--x") == 0)
      a = a - 1;
  }
  printf("%d", a);
  return 0;
}
