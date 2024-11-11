#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 2000000 + 10;
int n, m, tot = 0;
int hp[N], a[N], ans[N];
int main() {
  n = read(), m = read();
  for (register int i = 1, s = 0; i <= m; ++i)
    hp[i] = read(), s += hp[i], a[i] = s % n;
  a[m] = n;
  sort(a + 1, a + m + 1);
  for (register int i = m; i; --i) a[i] -= a[i - 1];
  for (register int i = 1, j = 1; i <= m; ++i)
    while (hp[i] > 0) ans[++tot] = i, hp[i] -= a[j], j = j % m + 1;
  while (tot % m) ans[++tot] = 1;
  printf("%d\n", tot / m);
  for (register int i = 1; i <= m; ++i) printf("%d%c", a[i], " \n"[i == m]);
  for (register int i = 1; i <= tot; ++i)
    printf("%d%c", ans[i], " \n"[i % m == 0]);
  return 0;
}
