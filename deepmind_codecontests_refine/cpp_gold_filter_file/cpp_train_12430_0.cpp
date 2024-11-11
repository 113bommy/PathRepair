#include <bits/stdc++.h>
int main() {
  long long t;
  while (scanf("%I64d", &t) != EOF) {
    if (t <= 3)
      printf("1\n");
    else
      for (long long i = 3;; i = i * 3)
        if (t % i) {
          printf("%I64d\n", t / i + 1);
          break;
        }
  }
  return 0;
}
