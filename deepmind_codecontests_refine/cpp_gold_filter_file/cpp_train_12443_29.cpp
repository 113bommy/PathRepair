#include <bits/stdc++.h>
int main(void) {
  long long i, j, p, q;
  while (~scanf("%I64d%I64d", &p, &q)) {
    long long ans = (p - q);
    long long dd = ans / 2;
    if (p < q || ans % 2 || dd & q) {
      printf("0\n");
      continue;
    }
    long long KK = 1;
    while (q) {
      if (q % 2) KK *= 2;
      q /= 2;
    }
    if (ans == 0) KK -= 2;
    printf("%I64d\n", KK);
  }
  return 0;
}
