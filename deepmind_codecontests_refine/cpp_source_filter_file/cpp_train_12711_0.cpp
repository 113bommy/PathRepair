#include <bits/stdc++.h>
using namespace std;
const long long N = 2100000;
inline long long add(long long x, long long y) {
  x += y;
  return x;
}
inline long long sub(long long x, long long y) {
  x -= y;
  return x;
}
inline long long read() {
  char c = getchar();
  long long x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
void FWT_or(long long a[], long long n, long long on) {
  for (long long i = 1; i < n; i <<= 1)
    for (long long j = 0; j < n; j += (i << 1))
      for (long long k = 0; k < i; k++) {
        long long u = a[j + k], t = a[j + k + i];
        a[j + k] = u;
        if (on == 1)
          a[j + k + i] = add(t, u);
        else
          a[j + k + i] = sub(t, u);
      }
}
void FWT_and(long long a[], long long n, long long on) {
  for (long long i = 1; i < n; i <<= 1)
    for (long long j = 0; j < n; j += (i << 1))
      for (long long k = 0; k < i; k++) {
        long long u = a[j + k], t = a[j + k + i];
        if (on == 1)
          a[j + k] = add(u, t);
        else
          a[j + k] = sub(u, t);
        a[j + k + i] = t;
      }
}
long long a[N], b[N], c[N];
char s[N];
signed main() {
  long long n = 1 << read();
  scanf("%s", s);
  for (long long i = 0; i < n; i++) a[i] = s[i] - '0';
  scanf("%s", s);
  for (long long i = 0; i < n; i++) b[i] = s[i] - '0';
  for (long long i = 0; i < n; i++)
    a[i] <<= (__builtin_popcount(i) << 1),
        b[i] <<= (__builtin_popcount(i) << 1);
  FWT_or(a, n, 1);
  FWT_or(b, n, 1);
  for (long long i = 0; i < n; i++) c[i] = a[i] * b[i];
  FWT_or(c, n, -1);
  for (long long i = 0; i < n; i++) c[i] >>= (__builtin_popcount(i) << 1);
  for (long long i = 0; i < n; i++) {
    printf("%lld", c[i] % 4, i == n - 1 ? '\n' : ' ');
  }
}
