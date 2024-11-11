#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, t = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; t |= c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9';
       x = (x << 3) + (x << 1) + (c ^ 48), c = getchar())
    ;
  return t ? -x : x;
}
struct dragon {
  int x, y;
  bool operator<(dragon k) const { return x < k.x; }
} a[1000];
int m, n;
int main() {
  m = read();
  n = read();
  for (register int i = 0; i < n; ++i) a[i].x = read(), a[i].y = read();
  sort(a, a + n);
  for (register int i = 0; i < n; ++i) {
    if (m <= a[i].x) {
      puts("NO");
      return 0;
    }
    m += a[i].y;
  }
  puts("YES");
}
