#include <bits/stdc++.h>
int main() {
  int n, i, r, j;
  char a[100][5], b[100][5];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%s", b[i]);
  }
  r = n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (strcmp(a[i], b[j]) == 0) {
        r--;
        strcpy(b[j], "0");
        break;
      }
    }
  }
  printf("%d\n", r);
  return 0;
}
