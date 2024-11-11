#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], b[100010], f[100010], L[100010], R[100010], s[100010 * 2];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; a[i++] = read())
    ;
  for (int i = 1; i <= m; ++s[b[i++] = read()])
    ;
  for (register int i = 1; i <= 200000; ++i) s[i] += s[i - 1];
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  a[0] = a[1] - 1000, a[n + 1] = a[n] + 1000;
  for (int i = 1; i <= n; ++i)
    if (a[i - 1] + 1 == a[i])
      L[i] = L[i - 1];
    else
      L[i] = i;
  for (int i = n; i >= 1; --i)
    if (a[i] + 1 == a[i + 1])
      R[i] = R[i + 1];
    else
      R[i] = i;
  for (int i = 1; i <= n; ++i) {
    int &cur = f[i];
    (cur < f[i - 1]) ? cur = f[i - 1] : 1;
    int mx = -1e9;
    if (L[i] == i) mx = f[i - 1] + s[a[i]] - s[a[i] - 1];
    (cur < mx) ? cur = mx : 1;
    for (int j = 1; b[j] <= a[i] && j <= m; ++j)
      if (i - a[i] + b[j] > 0) {
        int t = f[L[i - a[i] + b[j]] - 1] + s[a[i]] - s[b[j] - 1];
        (cur < t) ? cur = t : 1, (mx < t) ? mx = t : 1;
      }
    for (int j = m; b[j] >= a[i] && j; --j)
      if (i - a[i] + b[j] <= n)
        (f[R[i - a[i] + b[j]]] < mx + s[b[j]] - s[a[i]])
            ? f[R[i - a[i] + b[j]]] = mx + s[b[j]] - s[a[i]]
            : 1;
  }
  printf("%d\n", f[n]);
  return 0;
}
