#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 0, ch = getchar();
  while ('0' > ch || ch > '9') f ^= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
  return f ? -x : x;
}
int n, a[1010];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= (n >> 1); i++) printf("%d %d ", a[i], a[n - i + 1]);
  n & 1 ? printf("%d\n", a[(n >> 1) | 1]) : puts("");
  return 0;
}
