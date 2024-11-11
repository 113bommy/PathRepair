#include <bits/stdc++.h>
int main(void) {
  int m, n;
  char a[100000], b[10000];
  scanf("%s", a);
  scanf("%s", b);
  n = strlen(a);
  m = strlen(b);
  if (n = m) {
    if (strcmp(a, b) == 0)
      printf("-1");
    else
      printf("%d", m);
  } else if (n > m) {
    printf("%d", n);
  } else
    printf("%d", m);
  return 0;
}
