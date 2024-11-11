#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, m, an;
inline int work(int a, int b, int c) {
  return a == b && b == c ? 1 : a == b || b == c ? 3 : 6;
}
int main() {
  scanf("%I64d", &n);
  if (n % 3) {
    printf("0\n");
    return 0;
  }
  n /= 3;
  int A = (int)(pow(n, 1. / 3) + 1e-9);
  for (i = 2; i <= A; i++)
    if (n % i == 0) {
      int B = int(sqrt(n / i) + 1e-9);
      for (j = B; j >= i; j--)
        if (n / i % j == 0) {
          int C = n / i / j;
          if (i + j <= C) break;
          if (j <= C && (i + j + C) % 2 == 0) {
            int D = (i + j + C) / 2;
            an += work(D - C, D - j, D - i);
          }
        }
    }
  printf("%I64d\n", an);
  return 0;
}
