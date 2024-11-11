#include <bits/stdc++.h>
int main() {
  int a, b, c, n, i;
  scanf("%d%d%d%d", &a, &b, &c, &n);
  i = a + b - c;
  if (n - i <= 0 || c > a || c > b) {
    printf("-1");
  } else
    printf("%d", n - i);
}
