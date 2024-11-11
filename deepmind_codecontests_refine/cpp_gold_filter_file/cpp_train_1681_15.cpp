#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
int a[1010][1010], a0[1010][1010], b[1010][1010], b0[1010][1010],
    a1[1010][1010], b1[1010][1010], cnta[1010], cntb[1010];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      a0[i][j] = a[i][j] = b0[j][i] = b[j][i] = read();
  for (int i = 1; i <= n; i++) sort(a0[i] + 1, a0[i] + m + 1);
  for (int i = 1; i <= m; i++) sort(b0[i] + 1, b0[i] + n + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a0[i][j] > a0[i][j - 1]) a1[i][++cnta[i]] = a0[i][j];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (b0[i][j] > b0[i][j - 1]) b1[i][++cntb[i]] = b0[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = lower_bound(a1[i] + 1, a1[i] + cnta[i] + 1, a[i][j]) - a1[i];
      int y = lower_bound(b1[j] + 1, b1[j] + cntb[j] + 1, b[j][i]) - b1[j];
      int x1 = upper_bound(a1[i] + 1, a1[i] + cnta[i] + 1, a[i][j]) - a1[i];
      int y1 = upper_bound(b1[j] + 1, b1[j] + cntb[j] + 1, b[j][i]) - b1[j];
      printf("%d ", max(x, y) + max(cnta[i] - x1, cntb[j] - y1) + 1);
    }
    puts("");
  }
  return 0;
}
