#include <bits/stdc++.h>
int main() {
  int n, k, i;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    if (n % 10 == 0)
      n /= 10;
    else
      n--;
  }
  printf("%d", n);
  return 0;
}
