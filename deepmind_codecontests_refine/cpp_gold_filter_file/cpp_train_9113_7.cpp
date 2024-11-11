#include <bits/stdc++.h>
int read() {
  char ch = getchar();
  int x = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
long long pow(long long a, long long b, long long p) {
  if (!b) return 1;
  long long t = pow(a, b >> 1, p);
  t = t * t % p;
  if (b & 1) t = t * a % p;
  return t;
}
int main() {
  long long n, k;
  scanf("%I64d%I64d", &n, &k);
  if (n <= 60 && (1LL << n) < k)
    printf("1 1\n");
  else {
    long long s0 = 0;
    k--;
    long long kk = k;
    while (k) s0 += k / 2, k /= 2;
    k = kk;
    long long B = pow(2, n, 1000003);
    B = pow(B, k, 1000003);
    B = B * pow((1000003 + 1) / 2, s0, 1000003) % 1000003;
    long long st = pow(2, n, 1000003);
    long long A = 1;
    while (k--) {
      st--;
      if (!st) {
        A = 0;
        break;
      }
      A = A * st % 1000003;
    }
    A = A * pow((1000003 + 1) / 2, s0, 1000003) % 1000003;
    printf("%I64d %I64d", (B - A + 1000003) % 1000003, B);
  }
}
