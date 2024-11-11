#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int mo = 1000000007;
void upd(int &x, int y) { (x += y) >= mo ? x -= mo : 233; }
char s[2][N], t[N];
int n, m, ans, f[N][N][2];
int lcp[2][N][N], lcs[2][N][N];
void calc(bool count) {
  for (int k = 0; k <= 1; k++)
    for (int i = n; i >= 1; i--)
      for (int j = m; j >= 1; j--)
        lcp[k][i][j] = (s[k][i] == t[j] ? lcp[k][i + 1][j + 1] + 1 : 0);
  reverse(t + 1, t + m + 1);
  for (int k = 0; k <= 1; k++)
    for (int i = n; i >= 1; i--)
      for (int j = m; j >= 1; j--)
        lcs[k][i][j] = (s[k][i] == t[j] ? lcs[k][i + 1][j + 1] + 1 : 0);
  reverse(t + 1, t + m + 1);
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n + 1; i++) {
    for (int k = 0; k <= 1; k++) f[i][1][k] = 1;
    for (int j = 2; j <= i - 1; j++)
      if (!count || j * 2 < m)
        for (int k = 0; k <= 1; k++)
          if (lcp[k][i - j][j + 1] >= j && lcs[!k][i - j][m - j + 1] >= j)
            upd(f[i][2 * j + 1][k], 1);
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= 1; k++)
        if (i <= n && f[i][j][k] && s[k][i] == t[j]) {
          upd(f[i + 1][j + 1][k], f[i][j][k]);
          if (j + 1 <= m && s[!k][i] == t[j + 1])
            upd(f[i + 1][j + 2][!k], f[i][j][k]);
          if ((m - j + 1) > 2 && (m - j + 1) % 2 == 0 && (!count || j > 1)) {
            int l = (m - j + 1) / 2;
            if (lcp[k][i][j] >= l && lcs[!k][i][1] >= l) upd(ans, f[i][j][k]);
          }
        }
    for (int k = 0; k <= 1; k++) upd(ans, f[i][m + 1][k]);
  }
}
int main() {
  for (int i = 0; i <= 1; i++) scanf("%s", s[i] + 1);
  scanf("%s", t + 1);
  n = strlen(s[0] + 1);
  m = strlen(t + 1);
  calc(false);
  if (m != 1) {
    reverse(t + 1, t + m + 1);
    calc(true);
  }
  if (m == 2) {
    for (int i = 1; i <= n; i++)
      if (s[0][i] == t[1] && s[1][i] == t[2]) ans--;
    for (int i = 1; i <= n; i++)
      if (s[1][i] == t[1] && s[0][i] == t[2]) ans--;
  }
  printf("%d", (ans + mo) % mo);
}
