#include <bits/stdc++.h>
int main() {
  int n, i, ilk = 1;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    ilk += i;
    if (ilk > n) ilk %= n;
    printf("%d ", ilk);
  }
  printf("\n");
  return 0;
}
