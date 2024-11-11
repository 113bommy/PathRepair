#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
const int M = 1100000;
const long long mod = 1e9 + 7;
int n, m, q;
int L;
char s[N][N];
int sum[N][N];
int r[N][N];
int d[N][N];
char way[10] = {'R', 'G', 'Y', 'B'};
int check(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
struct query {
  int x1, y1, x2, y2;
} a[M];
int ans[M];
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    r[i][m] = 1;
    for (int j = m - 1; j >= 1; j--)
      if (s[i][j] == s[i][j + 1])
        r[i][j] = r[i][j + 1] + 1;
      else
        r[i][j] = 1;
  }
  L = min(n, m) / 2;
  for (int i = 0; i < 4; i++) {
    char ch = way[i];
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        sum[j][k] =
            sum[j - 1][k] + sum[j][k - 1] - sum[j - 1][k - 1] + (s[j][k] == ch);
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        if (s[j][k] == ch) {
          while (check(j, k, j + r[j][k] - 1, k + r[j][k] - 1) !=
                 r[j][k] * r[j][k])
            r[j][k]--;
        }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) d[i][j] = r[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] = 'R') {
        int len = d[i][j];
        if (i + len > n || j + len > m)
          r[i][j] = 0;
        else if (s[i + len][j] != 'Y' || s[i][j + len] != 'G' ||
                 s[i + len][j + len] != 'B')
          r[i][j] = 0;
        else {
          if (d[i + len][j] < len || s[i][j + len] < len ||
              s[i + len][j + len] < len)
            r[i][j] = 0;
          else
            r[i][j] = 2 * len;
        }
      } else
        r[i][j] = 0;
  for (int i = 1; i <= q; i++)
    scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
  for (int i = 1; i <= min(n, m); i++) {
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
        sum[j][k] =
            sum[j - 1][k] + sum[j][k - 1] - sum[j - 1][k - 1] + (r[j][k] == i);
    for (int j = 1; j <= q; j++) {
      int x1 = a[j].x1, y1 = a[j].y1, x2 = a[j].x2 - i + 1,
          y2 = a[j].y2 - i + 1;
      if (x2 < x1 || y2 < y1) continue;
      if (check(x1, y1, x2, y2) > 0) ans[j] = i * i;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
