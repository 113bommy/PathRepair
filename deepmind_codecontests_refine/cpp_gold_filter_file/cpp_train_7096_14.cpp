#include <bits/stdc++.h>
int rd() {
  int k = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar();
  return k;
}
const int N = 10001;
int l[N], r[N], cnt, n, m, f[N], s[N];
int main() {
  n = rd(), m = rd();
  for (int i = 1, o, x, y; i <= m; ++i) {
    o = rd(), x = rd(), y = rd();
    if (o)
      ++f[x], --f[y];
    else
      l[++cnt] = x, r[cnt] = y;
  }
  for (int i = 1; i < n; ++i) f[i] += f[i - 1];
  for (int i = 1; i < n; ++i) f[i] = (f[i] > 0), s[i] = s[i - 1] + f[i];
  for (int i = 1; i <= cnt; ++i)
    if (s[r[i] - 1] - s[l[i] - 1] == r[i] - l[i]) {
      puts("NO");
      return 0;
    }
  puts("YES");
  for (int i = 1, j = n + 2; i <= n; ++i) printf("%d ", f[i - 1] ? j : --j);
  return 0;
}
