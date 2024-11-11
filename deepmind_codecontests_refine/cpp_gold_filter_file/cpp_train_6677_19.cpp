#include <bits/stdc++.h>
using namespace std;
unsigned long long q, n, a, b, ans;
double x, y;
inline unsigned long long read() {
  char c = getchar();
  unsigned long long x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  return x;
}
int main() {
  q = read();
  for (register int i = 1; i <= q; i++) {
    ans = 0;
    n = read();
    a = read();
    b = read();
    x = double(a) / 1.0;
    y = double(b) / 2.0;
    if (x > y)
      ans = (n >> 1) * b + (n - (n >> 1 << 1)) * a;
    else
      ans = n * a;
    printf("%I64u\n", ans);
  }
  return 0;
}
