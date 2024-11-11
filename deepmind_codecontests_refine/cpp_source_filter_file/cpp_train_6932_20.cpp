#include <bits/stdc++.h>
using namespace std;
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long g = ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  }
}
int main() {
  long long A, B, C;
  scanf("%I64d%I64d%I64d", &A, &B, &C);
  if (A == 0) {
    if (C % B == 0)
      printf("0 %I64d\n", C / B);
    else
      puts("-1");
    return 0;
  }
  if (B == 0) {
    if (C % A == 0)
      printf("0 %I64d\n", C / A);
    else
      puts("-1");
    return 0;
  }
  bool flag = true;
  if (B < 0) {
    B = -B;
    flag = false;
  }
  long long mod = (-C + 20000000 * B) % B;
  while (mod < 0) mod += B;
  long long x1, x2;
  long long g = ex_gcd(A, B, x1, x2);
  if (mod % g != 0) {
    puts("-1");
    return 0;
  }
  long long e = x1 * (mod / g) % B;
  if (flag)
    printf("%I64d %I64d\n", e, -(A * e + C) / B);
  else
    printf("%I64d %I64d\n", e, (A * e + C) / B);
}
