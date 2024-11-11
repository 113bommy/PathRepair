#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    long long n;
    scanf("%d", &n);
    if (n % 2 == 0)
      printf("%lld\n", (n / 2) - 1);
    else
      printf("%lld\n", n / 2);
  }
  return 0;
}
