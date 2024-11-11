#include <bits/stdc++.h>
int main() {
  int l, i, j, c = 0;
  char a[500];
  scanf("%s", a);
  l = strlen(a);
  for (i = 1; i < l; i++) {
    if (a[i] >= 65 && a[i] <= 90) c++;
  }
  if (c == l - 1) {
    for (i = 0; i < l; i++) {
      if (a[i] >= 65 && a[i] <= 90)
        a[i] += 32;
      else
        a[i] -= 32;
    }
  }
  printf("%s", a);
  return 0;
}
