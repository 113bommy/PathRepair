#include <bits/stdc++.h>
using namespace std;
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
int n, a[5010], q, f[5010][5010];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read(), f[1][i] = a[i];
  }
  for (int i = 2; i <= n; ++i)
    for (int j = i; j <= n; ++j) f[i][j] = f[i - 1][j - 1] ^ f[i - 1][j];
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      f[i][j] = max(f[i][j], max(f[i - 1][j], f[i - 1][j - 1]));
  q = read();
  while (q--) {
    int l, r;
    l = read(), r = read();
    printf("%d\n", f[r - l + 1][r]);
  }
}
