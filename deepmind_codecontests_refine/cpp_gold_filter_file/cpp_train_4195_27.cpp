#include <bits/stdc++.h>
inline int read() {
  int r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
int a, b, c, d;
inline void work() {
  a = read(), b = read(), c = read(), d = read();
  if (a > 1ll * b * c) return (void)puts("-1");
  if (c <= d) return (void)printf("%d\n", a);
  int l = 0, r = (c + d - 1) / d + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (a >= 1ll * (mid - 1) * d * b)
      l = mid;
    else
      r = mid;
  }
  printf("%lld\n", 1ll * a * l - 1ll * d * b * (l - 1) * l / 2);
}
int main() {
  int t = read();
  while (t--) work();
  return 0;
}
