#include <bits/stdc++.h>
using namespace std;
long long fib[1 << 10];
int main() {
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < 45; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 45; i++) {
    for (int j = 0; j < 45; j++) {
      for (int k = 0; k < 45; k++) {
        if (fib[i] + fib[j] + fib[k] == n) {
          printf("%lld %lld %lld\n", fib[i], fib[j], fib[k]);
          return 0;
        }
      }
    }
  }
  printf("I'm too stupid to solve this problem\n");
  return 0;
}
