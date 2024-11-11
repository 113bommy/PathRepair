#include <bits/stdc++.h>
using namespace std;
long long N, M, K;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  scanf("%I64d%I64d%I64d", &N, &M, &K);
  long long g = gcd(N * M, K);
  long long x = N * M / g, y = K / g;
  if (y > 2) {
    puts("NO");
    return 0;
  }
  long long t = gcd(2 * N, K);
  if (t >= 2) {
    long long a = 2 * N / t;
    long long b = 2 * N * M / a / K;
    printf("YES\n");
    printf("0 0\n");
    printf("0 %I64d\n", b);
    printf("%I64d 0\n", a);
  } else {
    t = gcd(2 * M, K);
    long long b = 2 * M / t;
    long long a = 2 * M * N / b / K;
    printf("YES\n");
    printf("0 0\n");
    printf("0 %I64d\n", b);
    printf("%I64d 0\n", a);
  }
  return 0;
}
