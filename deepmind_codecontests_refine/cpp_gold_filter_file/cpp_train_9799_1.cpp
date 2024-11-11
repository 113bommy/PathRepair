#include <bits/stdc++.h>
int main() {
  char a[100];
  scanf("%s", a);
  int n = strlen(a), i;
  int k = (n - 1) / 2;
  if (n == 1) {
    printf("%c", a[k]);
    exit(0);
  }
  for (i = 0; i <= n / 2; i++) {
    if (i == 0) {
      printf("%c", a[k]);
      continue;
    }
    if (k + i < n) {
      printf("%c", a[k + i]);
    }
    if (k - i >= 0) {
      printf("%c", a[k - i]);
    }
  }
}
