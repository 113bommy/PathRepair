#include <bits/stdc++.h>
int main() {
  long int n, k, i;
  scanf("%ld%ld", &n, &k);
  for (i = 0; i < k; i++) {
    if (n % 10 == 0 && n != 0)
      n = n / 10;
    else
      n--;
  }
  printf("%ld", n);
  return 0;
}
