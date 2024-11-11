#include <bits/stdc++.h>
int a[1007][1007];
int n, i, s = 0, j, dem = 0;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= 3; j++) {
      scanf("%d", &a[i][j]);
    }
    printf("\n");
  }
  int j = 1;
  while (j <= 3) {
    for (i = 1; i <= n; i++) {
      s = s + a[i][j];
    }
    if (s == 0) {
      dem++;
    }
    s = 0;
    j++;
  }
  if (dem == 3) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}
