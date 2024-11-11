#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int N = 1000010;
int n, m, i, j, k, l, x, p;
int a[N], home[N], f[N];
int main() {
  read(n);
  for (i = 1; i <= n; i++) read(a[i]);
  for (i = 1; i <= n; i++) read(x), home[x] = i;
  for (i = 1; i <= n; i++) a[i] = n - home[a[i]] + 1;
  m = 0;
  for (i = 1; i <= n; i++) {
    p = lower_bound(f + 1, f + 1 + m, a[i]) - f;
    if (p > m)
      f[++m] = a[i];
    else
      f[p] = a[i];
  }
  printf("%d\n", m);
  scanf("\n");
  return 0;
}
