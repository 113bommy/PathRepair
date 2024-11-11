#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 9;
int N, W, B;
long long POW(long long base, int exp) {
  if (!exp) return 1;
  if (exp & 1) return POW(base, exp - 1) * base % mo;
  long long tmp(POW(base, exp >> 1));
  return tmp * tmp % mo;
}
long long f(int x) {
  long long ret(1);
  for (int i = 2; i <= x; i++) ret *= i, ret %= mo;
  return ret;
}
long long C(int n, int m) {
  return f(n) * POW(f(m) * f(n - m) % mo, mo - 2) % mo;
}
int main() {
  scanf("%d%d%d", &N, &W, &B);
  printf("%I64d\n", f(W) * f(B) % mo * (W - 1) % mo * C(W + B - 3, N - 3) % mo);
  return 0;
}
