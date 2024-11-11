#include <bits/stdc++.h>
int main() {
  char a[100000];
  int n = 0, m = 0, i, p;
  scanf("%d", &p);
  scanf("%s", a);
  for (i = 0; i < p; i++) {
    if (a[i] == 'z') n++;
    if (a[i] == 'n') m++;
  }
  for (i = 0; i < m; i++) {
    printf("1 ");
  }
  for (i = 0; i < n; i++) {
    printf("0 ");
  }
  return 0;
}
