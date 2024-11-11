#include <bits/stdc++.h>
int main(void) {
  int n, i, j, flag;
  scanf("%d", &n);
  char a[n + 1][101];
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  printf("NO\n");
  for (i = 1; i < n; i++) {
    flag = 0;
    for (j = i - 1; j >= 0; j--) {
      if (strcmp(a[i], a[j]) == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
