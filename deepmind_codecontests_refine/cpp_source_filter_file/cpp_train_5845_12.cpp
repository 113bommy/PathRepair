#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, m, h[N], a[N], ans[N], tot = 0;
int main() {
  n = gi(), m = gi();
  for (int i = 1, s = 0; i <= m; i++) s += (h[i] = gi()), a[i] = s % n;
  a[m] = n, sort(a + 1, a + m + 1);
  for (int i = m; i; i--) a[i] -= a[i - 1];
  for (int i = 1, j = 1; i <= m; i++)
    while (h[i] > 0) ans[++tot] = i, h[i] -= a[j], j = j % m + 1;
  while (tot % m) ans[++tot] = 1;
  printf("%d\n", tot / m);
  for (int i = 1; i <= m; i++) printf("%d%c", a[i], " \n"[i == m]);
  for (int i = 1; i <= tot; i++) printf("%d%c", ans[i], " \n"[i % m == 0]);
  return 0;
}
