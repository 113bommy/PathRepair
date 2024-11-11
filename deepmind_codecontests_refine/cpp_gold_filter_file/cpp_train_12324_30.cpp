#include <bits/stdc++.h>
int main(void) {
  int n, i, x = 0;
  char imp[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", &imp);
    if (!strcmp(imp, "X++") || !strcmp(imp, "++X"))
      x = x + 1;
    else if (!strcmp(imp, "X--") || !strcmp(imp, "--X"))
      x = x - 1;
  }
  printf("%d\n", x);
  return 0;
}
