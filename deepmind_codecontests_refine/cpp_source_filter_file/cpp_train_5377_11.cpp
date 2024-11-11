#include <bits/stdc++.h>
int main() {
  int n, k, i;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    if (n % i == 0) {
      k = i;
    }
  }
  printf("%d", k);
  return 0;
}
