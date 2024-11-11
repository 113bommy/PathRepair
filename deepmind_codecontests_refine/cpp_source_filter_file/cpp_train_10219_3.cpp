#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, sl, fh, ans, a[1000010], l[1000010], r[1000010];
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
int main() {
  n = rd();
  m = rd();
  for (int i = 1; i <= n; ++i) l[i] = n + 1;
  for (int i = 1; i <= m; ++i) {
    a[i] = rd();
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
  }
  for (int x, i = 1; i <= n; ++i) {
    x = i - 1;
    if (x && r[x] < l[i]) ans++;
    if (x && r[i] < l[x]) ans++;
    if (l[i] == n + 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
