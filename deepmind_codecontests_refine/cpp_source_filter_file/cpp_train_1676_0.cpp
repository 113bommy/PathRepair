#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void chkmin(T &a, T b) {
  if (a > b) a = b;
}
const int inf = 0x3f3f3f3f;
pair<int, int> rpt[2 * 20005];
int first[20005], second[20005], ans;
int n, m, p, ox, oy, dp[2][20005], ep[2][20005];
int val(int a, int b) {
  int res = first[a] + second[b];
  return res >= p ? res - p : res;
}
void go(int sx, int sy, int fx, int fy) {
  int d = fx + fy - sx - sy;
  int mid = d >> 1, up, dw;
  int u = 0, v = 1;
  dp[0][0] = 0;
  for (int i = 1; i <= mid; i++) {
    if (i == mid)
      for (int j = 0; j <= i; j++) ep[v][j] = j;
    up = min(i, m - sy - 1);
    dw = max(0, sx + i - n + 1);
    if (dw == 0) dw++, dp[v][0] = dp[u][0] + val(sx + i, sy);
    if (up == i) up--, dp[v][i] = dp[u][i - 1] + val(sx, sy + i);
    for (int j = dw; j <= up; j++)
      dp[v][j] = max(dp[u][j], dp[u][j - 1]) + val(sx + i - j, sy + j);
    swap(u, v);
  }
  for (int i = 0; i <= mid; i++) ep[u][i] = i;
  for (int i = mid + 1; i <= d; i++) {
    up = min(i, m - sy - 1);
    dw = max(0, sx + i - n + 1);
    if (dw == 0)
      dw++, dp[v][0] = dp[u][0] + val(sx + i, sy), ep[v][0] = dp[u][0];
    if (up == i)
      up--, dp[v][i] = dp[u][i - 1] + val(sx, sy + i), ep[v][i] = ep[u][i - 1];
    for (int j = dw; j <= up; j++) {
      dp[v][j] = max(dp[u][j], dp[u][j - 1]) + val(sx + i - j, sy + j);
      ep[v][j] = dp[u][j] > dp[u][j - 1] ? ep[u][j] : ep[u][j - 1];
    }
    swap(u, v);
  }
  int k = ep[u][fy - sy];
  oy = sy + k;
  ox = sx + sy + mid - oy;
  if (!sx && !sy && fx == n - 1 && fy == m - 1) ans = dp[u][m - 1];
}
void func(int sx, int sy, int fx, int fy) {
  int d = fx + fy - sx - sy;
  if (d <= 1) return;
  int mid = d >> 1;
  go(sx, sy, fx, fy);
  rpt[sx + sy + mid] = pair<int, int>(ox, oy);
  func(sx, sy, ox, oy);
  func(ox, oy, fx, fy);
  return;
}
int main() {
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < n; i++) scanf("%d", &first[i]), first[i] %= p;
  for (int i = 0; i < m; i++) scanf("%d", &second[i]), second[i] %= p;
  rpt[0] = pair<int, int>(0, 0);
  rpt[m + n - 2] = pair<int, int>(n - 1, m - 1);
  func(0, 0, n - 1, m - 1);
  printf("%d\n", ans + val(0, 0));
  for (int i = 1; i <= m + n - 2; i++) {
    if (rpt[i].first == rpt[i - 1].first + 1)
      putchar('C');
    else
      putchar('S');
  }
  return 0;
}
