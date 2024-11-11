#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 1e5 + 1;
inline int read() {
  char ch = getchar();
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  int x = 0;
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
int n, a[N];
int s = 0, f[N];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), s += a[i];
  int ans = a[1];
  f[1] = a[1];
  for (int i = 2; i <= n; i++)
    f[i] = max(f[i - 1] + a[i], a[i]), ans = max(ans, f[i]);
  printf("%d\n", ans * 2 - s);
  return 0;
}
