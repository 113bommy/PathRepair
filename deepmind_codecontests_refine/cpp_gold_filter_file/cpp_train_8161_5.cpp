#include <bits/stdc++.h>
int a[110][110];
int n, k, z;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (j == i)
        printf("%d", k);
      else
        printf(" 0 ");
    printf("\n");
  }
  return 0;
}
