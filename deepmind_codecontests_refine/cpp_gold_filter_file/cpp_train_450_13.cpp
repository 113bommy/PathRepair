#include <bits/stdc++.h>
int getint() {
  int ret = 0;
  bool ok = false;
  for (;;) {
    int c = getchar();
    if (c >= '0' && c <= '9')
      ret = (ret << 3) + ret + ret + c - '0', ok = true;
    else if (ok)
      return ret;
  }
}
int n, K;
long long A[2010];
const long long M = 1000000007;
void GCD(long long, long long, long long &, long long &);
long long INV(int x) {
  long long rx, ry;
  GCD(x, M, rx, ry);
  rx %= M;
  return rx;
}
void GCD(long long m, long long n, long long &x, long long &y) {
  if (!n) {
    x = 1, y = 0;
    return;
  }
  GCD(n, m % n, y, x);
  y -= x * (m / n);
}
long long C[2010];
int main() {
  n = getint(), K = getint();
  for (int i = 1; i <= n; i++) A[i] = getint();
  C[0] = 1;
  for (int i = 1; i <= n - 1; i++)
    C[i] = C[i - 1] * (K - 1 + i) % M * INV(i) % M;
  for (int i = 1; i <= n; i++) {
    long long ret = 0;
    for (int j = 1; j <= i; j++) ret = (ret + C[i - j] * A[j]) % M;
    printf("%d ", ret < 0 ? ret + M : ret);
  }
  return 0;
}
