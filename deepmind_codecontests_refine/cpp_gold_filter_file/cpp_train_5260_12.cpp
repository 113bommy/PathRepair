#include <bits/stdc++.h>
using namespace std;
int x, i, k, n;
int a[100010];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  n = read();
  k = read();
  for (i = 1; i <= n; i++) a[i] = getchar() - 'a';
  for (i = 1; i <= n; i++) {
    x = 25 - a[i];
    if (x > a[i]) {
      if (x <= k)
        k -= x, a[i] = 25;
      else
        a[i] += k, k = 0;
    } else {
      if (a[i] <= k)
        k -= a[i], a[i] = 0;
      else
        a[i] -= k, k = 0;
    }
    if (!k) break;
  }
  if (k)
    puts("-1");
  else
    for (i = 1; i <= n; i++) putchar(a[i] + 'a');
}
