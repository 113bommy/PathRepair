#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30);
inline int in() {
  char ch = getchar();
  int f = 1, tmp = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    tmp = (tmp << 1) + (tmp << 3) + (ch - '0');
    ch = getchar();
  }
  return tmp * f;
}
int n, m;
long long a[55], b[55];
long long ans;
int main() {
  n = in(), m = in();
  for (int i = 1; i <= n; i++) a[i] = in();
  for (int i = 1; i <= m; i++) b[i] = in();
  int cur = 0;
  ans = -(1ll << 60);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] * b[j] > ans) ans = a[i] * b[j], cur = i;
  ans = -(1ll << 60);
  for (int i = 1; i <= n; i++)
    if (i != cur)
      for (int j = 1; j <= m; j++)
        if (a[i] * b[j] > ans) ans = a[i] * b[j];
  printf("%I64d\n", ans);
  return 0;
}
