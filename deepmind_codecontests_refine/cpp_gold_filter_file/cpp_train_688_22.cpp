#include <bits/stdc++.h>
int a[1010];
int n;
int main() {
  scanf("%d", &n);
  a[1] = 1;
  a[2] = 1;
  for (int i = 3; i <= 40; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  for (int i = 1; i <= n; i++) {
    int f = 0;
    for (int j = 1; j <= 30; j++) {
      if (i == a[j]) {
        f = 1;
        break;
      }
    }
    if (f == 0)
      printf("o");
    else if (f == 1)
      printf("O");
  }
  printf("\n");
}
