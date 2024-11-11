#include <bits/stdc++.h>
int a[10] = {5, 8, 17, 2, 20, 11};
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 2)
    printf("-1\n");
  else if (n == 3)
    printf("210\n");
  else {
    int s = (n - 4) % 6;
    printf("1");
    if (s == 2 || s == 4 || s == 5) {
      for (int i = n - 4; i > 0; i--) {
        printf("0");
      }
      printf("%d0\n", a[s]);
    } else {
      for (int i = n - 3; i > 0; i--) {
        printf("0");
      }
      printf("%d0\n", a[s]);
    }
  }
  return 0;
}
