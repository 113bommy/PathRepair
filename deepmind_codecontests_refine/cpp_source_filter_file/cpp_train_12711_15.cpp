#include <bits/stdc++.h>
namespace io {
int F() {
  int F = 1, n = 0;
  char ch;
  while ((ch = getchar()) != '-' && (ch < '0' || ch > '9'))
    ;
  ch == '-' ? F = 0 : n = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') n = n * 10 + ch - '0';
  return F ? n : -n;
}
long long G() {
  long long F = 1, n = 0;
  char ch;
  while ((ch = getchar()) != '-' && (ch < '0' || ch > '9'))
    ;
  ch == '-' ? F = 0 : n = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') n = n * 10 + ch - '0';
  return F ? n : -n;
}
}  // namespace io
int R(int l, int r) { return (rand() << 15 | rand()) % (r - l + 1) + l; }
long long a[2222222], b[2222222];
char A[2222222], B[2222222];
char c[2222222];
int main() {
  int n = io::F();
  scanf("%s%s", A, B);
  for (register int i = 0; i < 1 << n; ++i)
    a[i] = (long long)(A[i] - '0') << 2 * __builtin_popcount(i),
    b[i] = (long long)(B[i] - '0') << 2 * __builtin_popcount(i);
  for (register int i = 0; i < n; ++i)
    for (register int j = 1 << i; j < 1 << n; j = j + 1 | 1 << i)
      a[j] += a[j ^ 1 << i], b[j] += b[j ^ 1 << i];
  for (register int i = 0; i < 1 << n; ++i) a[i] *= b[i];
  for (register int i = 0; i < n; ++i)
    for (register int j = 1 << i; j < 1 << n; j = j + 1 | 1 << i)
      a[j] -= a[j ^ 1 << i];
  for (register int i = 0; i < 1 << n; ++i)
    c[i] = '0' + (a[i] >> 2 * __builtin_popcount(i)) % 4;
  puts(c);
  return 0;
}
