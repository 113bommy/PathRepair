#include <bits/stdc++.h>
const long long M = 5005, JYY = 998244353;
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x < y ? x : y; }
long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * y;
}
long long n, m, k, stl2[M][M];
void init() {
  stl2[0][0] = 1;
  for (long long i = 1; i < M; i++) {
    for (long long j = 1; j <= i; j++) {
      stl2[i][j] = (stl2[i - 1][j - 1] + j * stl2[i - 1][j] % JYY) % JYY;
    }
  }
}
long long pow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % JYY;
    x = (x * x) % JYY;
    y >>= 1;
  }
  return res;
}
void solve() {
  n = read(), m = read(), k = read();
  init();
  long long ans = 0, fac = 1, c = 1, p = 1;
  for (long long i = 1; i <= k; i++) {
    fac = (fac * i) % JYY;
    c = (c * (n - i + 1)) % JYY * pow(i, JYY - 2) % JYY;
    p = (p * pow(m, JYY - 2)) % JYY;
    ans = (ans + stl2[k][i] * fac % JYY * c % JYY * p % JYY) % JYY;
  }
  printf("%lld\n", ans);
}
signed main() { solve(); }
