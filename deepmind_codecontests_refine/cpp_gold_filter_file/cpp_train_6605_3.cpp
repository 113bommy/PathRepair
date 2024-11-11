#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void pr1(int x) { write(x), putchar(' '); }
inline void pr2(int x) { write(x), puts(""); }
int N, ex[25];
long long mod, f[1050000], g[1050000];
inline long long mul(long long a, long long b) {
  return (a * b - (long long)((long double)a / mod * b) * mod + mod) % mod;
}
inline void FWT(long long *a, int id) {
  for (int i = 2; i <= N; i *= 2) {
    int ul = i >> 1;
    for (int j = 0; j < N; j += i) {
      for (int k = 0; k < ul; k++) {
        long long x = a[j + k], y = a[j + k + ul];
        a[j + k] = (x + y) % mod, a[j + k + ul] = (x - y + mod) % mod;
      }
    }
  }
  if (id == -1)
    for (int i = 0; i < N; i++) a[i] /= N;
}
inline long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
int main() {
  int n = read();
  N = (1 << n);
  long long T;
  scanf("%lld", &T);
  mod = 1LL * read() * N;
  for (int i = 0; i < N; i++) f[i] = read();
  for (int i = 0; i <= n; i++) ex[i] = read();
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i >> j & 1) cnt++;
    g[i] = ex[cnt];
  }
  FWT(f, 1), FWT(g, 1);
  for (int i = 0; i < N; i++) f[i] = mul(f[i], power(g[i], T));
  FWT(f, -1);
  mod /= N;
  for (int i = 0; i < N; i++) pr2(f[i] % mod);
  return 0;
}
