#include <bits/stdc++.h>
using namespace std;
int n, m, h[200010], d[200010], fl[200010][20], fr[200010][20];
long long l[200010] = {0}, r[200010] = {0};
int FindL(int x, int y) {
  if (x > y) return 0;
  int k = log2(y - x + 1);
  return (l[fl[x][k]] > l[fl[y - (1 << k) + 1][k]]) ? fl[x][k]
                                                    : fl[y - (1 << k) + 1][k];
}
int FindR(int x, int y) {
  if (x > y) return 0;
  int k = log2(y - x + 1);
  return (r[fr[x][k]] > r[fr[y - (1 << k) + 1][k]]) ? fr[x][k]
                                                    : fr[y - (1 << k) + 1][k];
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
  for (int i = n + 1; i < n + n; ++i) d[i] = d[i - n], h[i] = h[i - n];
  for (int i = 1; i < 2 * n; ++i)
    l[i] = l[i - 1] - 2 * h[i - 1] - d[i - 1] + 2 * h[i],
    r[i] = r[i - 1] - 2 * h[i - 1] + d[i - 1] + 2 * h[i];
  for (int i = 1; i < 2 * n; ++i) fl[i][0] = i, fr[i][0] = i;
  for (int j = 1; (1 << j) < 2 * n; ++j)
    for (int i = 1; i + (1 << j) - 1 < 2 * n; ++i) {
      fl[i][j] = (l[fl[i][j - 1]] > l[fl[i + (1 << (j - 1))][j - 1]])
                     ? fl[i][j - 1]
                     : fl[i + (1 << (j - 1))][j - 1];
      fr[i][j] = (r[fr[i][j - 1]] > r[fr[i + (1 << (j - 1))][j - 1]])
                     ? fr[i][j - 1]
                     : fr[i + (1 << (j - 1))][j - 1];
    }
  l[0] = r[0] = -1e18;
  int u, v, x, y, t, g;
  for (int _ = 0; _ < m; ++_) {
    scanf("%d%d", &x, &y);
    if (x > y)
      swap(x, y), x++, y--;
    else
      swap(x, y), x++, y--, y += n;
    u = FindL(x, y);
    v = FindR(x, y);
    if (u == v) {
      t = FindR(u + 1, y);
      g = FindL(x, u - 1);
      printf("%I64d\n", max(r[t] + l[u], r[v] + l[g]));
    } else
      printf("%I64d\n", r[v] + l[u]);
  }
  return 0;
}
