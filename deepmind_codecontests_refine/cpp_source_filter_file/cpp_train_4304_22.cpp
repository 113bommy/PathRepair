#include <bits/stdc++.h>
int main() {
  int a[19000], b, c, n;
  a[1] = 1;
  int i = 2;
  while (i <= 18257) {
    a[i] = a[i - 1] + 6 * i;
    i++;
  }
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", a[n]);
  }
  return 0;
}
