#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 1111 * 1111 * 1111;
const long long MAXLINT = MAXINT * 1ll * MAXINT;
const long double EPS = 1e-10;
const int MAXN = 15;
const int BASE = 1000000007;
int n, m, k;
int a[MAXN + 1][MAXN + 1];
int code[MAXN + 1];
int was[MAXN + 1][MAXN + 1][MAXN + 1];
long long ans;
void dfs(int row, int column, int cnt) {
  if (row == n) {
    for (int i = 1; i <= cnt; i++)
      for (int j = i + 1; j <= cnt; j++)
        if (code[i] == code[j] && code[i]) return;
    int a, b;
    a = b = 0;
    for (int i = 1; i <= cnt; i++)
      if (code[i])
        a++;
      else
        b++;
    a = k - a;
    int res = 1;
    for (int i = 0; i < b; i++) res *= a--;
    ans += res;
    if (ans > BASE) ans -= BASE;
    return;
  }
  for (int c = 1; c <= min(cnt + 1, k); c++) {
    if (was[row][column][c]) continue;
    if (a[row][column] && code[c] && a[row][column] != code[c]) continue;
    bool f = code[c] == 0;
    if (f) code[c] = a[row][column];
    for (int i = row; i < n; i++)
      for (int j = column; j < m; j++) was[i][j][c]++;
    if (column < m - 1)
      dfs(row, column + 1, max(c, cnt));
    else
      dfs(row + 1, 0, max(c, cnt));
    for (int i = row; i < n; i++)
      for (int j = column; j < m; j++) was[i][j][c]--;
    if (f) code[c] = 0;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n + m - 1 > k) {
    printf("0");
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  dfs(0, 0, 0);
  printf("%I64d", ans);
  return 0;
}
