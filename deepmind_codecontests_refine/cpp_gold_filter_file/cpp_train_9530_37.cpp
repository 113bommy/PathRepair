#include <bits/stdc++.h>
int main() {
  int n, i, st, e, fl = 0;
  scanf("%d", &n);
  char s[100];
  for (i = 0; i < n; i++) {
    scanf("%s%d%d", s, &st, &e);
    if (st >= 2400 && e - st > 0) fl = 1;
  }
  if (fl == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
