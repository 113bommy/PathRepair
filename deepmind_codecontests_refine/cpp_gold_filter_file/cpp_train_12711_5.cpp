#include <bits/stdc++.h>
using namespace std;
const int RLEN = 2 << 18 | 1;
inline char nc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? -1 : *ib++;
}
inline int rd() {
  char ch = nc();
  int i = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    i = (i << 1) + (i << 3) + ch - '0';
    ch = nc();
  }
  return i * f;
}
const int N = (1 << 21) + 50;
int n, m;
char A[N], B[N];
unsigned long long a[N], b[N];
inline void fmt(unsigned long long *t) {
  for (int i = 1; i < m; i <<= 1)
    for (int j = 0; j < m; j++)
      if (i & j) t[j] += t[i ^ j];
}
inline void dfmt(unsigned long long *t) {
  for (int i = 1; i < m; i <<= 1)
    for (int j = 0; j < m; j++)
      if (i & j) t[j] -= t[i ^ j];
}
int main() {
  scanf("%d%s%s", &n, A, B);
  m = 1 << n;
  for (int i = 0; i < m; i++)
    a[i] = (A[i] - '0') * (1ull << (2 * __builtin_popcount(i))),
    b[i] = (B[i] - '0') * (1ull << (2 * __builtin_popcount(i)));
  fmt(a);
  fmt(b);
  for (int i = 0; i < m; i++) b[i] = a[i] * b[i];
  dfmt(b);
  for (int i = 0; i < m; i++)
    putchar('0' + ((b[i] >> (2 * __builtin_popcount(i))) & 3));
}
