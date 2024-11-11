#include <bits/stdc++.h>
int t, a, b, c, k;
inline int read() {
  int d = 0, f = 0, c = getchar();
  for (; c < 48 || c > 57; c = getchar()) f |= (c == '-');
  for (; c > 47 && c < 58; c = getchar()) d = (d << 1) + (d << 3) + (c ^ 48);
  return f ? -d : d;
}
inline void swap(int& a, int& b) { a ^= b ^= a ^= b; }
int main() {
  t = read();
  for (; t; t--) {
    a = read(), b = read(), c = read();
    if (a < b) swap(a, b);
    k = a - b;
    if (b > k)
      puts("-1");
    else if (c > 2 * k)
      puts("-1");
    else if (c > k)
      printf("%d\n", c - k);
    else
      printf("%d\n", c + k);
  }
  return 0;
}
