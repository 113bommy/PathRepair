#include <bits/stdc++.h>
int main() {
  unsigned long long int n, s = 0;
  int i = 1;
  scanf("%llu", &n);
  for (i = 1; i < n; i++) {
    s = s + i;
    if (n == s) {
      printf("%d", i);
      return 0;
    }
    if ((n - s) <= i) {
      printf("%llu", (n - s));
      return 0;
    } else {
      continue;
    }
  }
  return 0;
}
