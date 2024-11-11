#include <bits/stdc++.h>
int main() {
  int i;
  char a[2][105];
  scanf("%s %s", a[0], a[1]);
  for (i = 0; a[0][i] != NULL; i++) {
    if ('A' <= a[0][i] && a[0][i] <= 'Z') a[0][i] += 'a' - 'A';
  }
  for (i = 0; a[1][i] != NULL; i++) {
    if ('A' <= a[1][i] && a[1][i] <= 'Z') a[1][i] += 'a' - 'A';
  }
  printf("%d", strcmp(a[0], a[1]));
  return 0;
}
