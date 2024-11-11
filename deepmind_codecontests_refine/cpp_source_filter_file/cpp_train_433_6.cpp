#include <bits/stdc++.h>
using namespace std;
bitset<1250005> f[52][26];
int n, S, a[55], ans[2][26];
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(2 * n); i++) scanf("%d", &a[i]);
  sort(a + 1, a + 2 * n + 1, greater<int>());
  ans[1][1] = a[2 * n];
  ans[2][n] = a[2 * n - 1];
  f[0][0][0] = 1;
  for (int i = (int)(1); i <= (int)(2 * n - 2); i++) S += a[i];
  for (int i = (int)(1); i <= (int)(2 * n - 2); i++)
    for (int j = (int)(0); j <= (int)(min(n - 1, i - 1)); j++) {
      f[i][j] |= f[i - 1][j];
      f[i][j + 1] |= f[i - 1][j] << a[i];
    }
  int v = 1 << 30, p = -1;
  for (int i = (int)(0); i <= (int)(S); i++)
    if (f[2 * n - 2][n - 1][i])
      if (max(S - i, i) <= v) v = max(S - i, i), p = i;
  int v1 = 2 * n - 2, v2 = n - 1;
  int p1 = 2, p2 = n - 1;
  for (; v1; v1--)
    if (p >= a[v1] && v2 && f[v1 - 1][v2 - 1][p - a[v1]])
      ans[1][p1++] = a[v1], v2--, p -= a[v1];
    else
      ans[2][p2--] = a[v1];
  for (int i = (int)(1); i <= (int)(2); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      printf("%d%c", ans[i][j], j == n ? '\n' : ' ');
}
