#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000009;
const long long N = 1000010;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
long long calc(long long x) { return x % 2 ? x / 2 : 0; }
long long f[N], g[N];
signed main() {
  long long n = read(), sum = 1;
  f[0] = 0;
  f[1] = 2;
  g[1] = 4;
  for (long long i = 2; i <= n; ++i) g[i] = (g[i - 1] * 2 + 4) % mod;
  for (long long i = 2; i <= n - 2; ++i) {
    f[i] = (sum * 2 % mod + f[i - 1] + g[calc(i)] * sum * 2 % mod) % mod;
    if (i % 2) sum = sum * (g[i / 2] + 1) % mod;
  }
  cout << (f[n - 2] * f[n - 2] * 2 % mod + f[n - 2] * 8 % mod + 10) % mod
       << endl;
  return 0;
}
