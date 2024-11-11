#include <bits/stdc++.h>
int main() {
  int n, i;
  unsigned long long t;
  scanf("%d", &n);
  t = 0;
  for (i = 1; i < n + 1; i++) {
    t = t + pow(2, i);
  }
  if (n == 5) {
    t = t - 2;
  }
  printf("%lld", t);
  return (0);
}
