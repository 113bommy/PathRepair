#include <bits/stdc++.h>
int main() {
  int n, i, flag = 0;
  int a[1005];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    if (a[i] == 1) flag = 1;
  }
  if (flag = 1)
    printf("-1\n");
  else
    printf("1\n");
}
