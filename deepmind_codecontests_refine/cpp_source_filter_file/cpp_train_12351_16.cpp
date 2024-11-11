#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
const int N = 2000 + 5;
const int mo = 998244353;
int n;
long long a, b, p;
long long A[N], B[N];
long long f[N][N], v[N], g[N];
long long getpow(long long a, long long b) {
  long long ans = 1;
  a %= mo;
  while (b) {
    if (b & 1) ans = ans * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return ans;
}
int main() {
  read(n);
  read(a), read(b);
  p = a * getpow(b, mo - 2);
  A[0] = B[0] = 1;
  for (int i = 1; i <= n; i++)
    A[i] = A[i - 1] * p % mo, B[i] = B[i - 1] * (1 - p) % mo;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      f[i][j] =
          (f[i - 1][j - 1] * B[i - j] % mo + f[i - 1][j] * A[j] % mo) % mo;
    }
  }
  for (int i = 1; i <= n; i++) {
    v[i] = 1;
    for (int j = 1; j < i; j++) (v[i] -= v[j] * f[i][j] % mo) %= mo;
  }
  for (int i = 2; i <= n; i++) {
    g[i] = i * (i - 1) / 2;
    for (int j = 1; j < i; j++) {
      (g[i] += v[j] * f[i][j] % mo *
               ((g[j] + g[i - j] - (i - j) * (i - j - 1) / 2) % mo) % mo) %= mo;
    }
    g[i] = g[i] * getpow(1 - v[i] * f[i][i], mo - 2) % mo;
  }
  printf("%lld\n", (g[n] + mo) % mo);
  return 0;
}
