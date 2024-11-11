#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 510;
const int MAX = 1000000100;
const int mod = 100000000;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const double EPS = 0.00000001;
const long long MOD = 998244353;
const int INF = 1000000010;
const double pi = acos(-1.0);
char s[N];
int n, a[2 * N][2 * N], b[N][N];
int g = 0, q[N * N], f[N * N], xm[N * N], ym[N * N], xx[N * N], yx[N * N];
void dfs(int x, int y) {
  b[x][y] = g;
  f[g]++;
  xm[g] = min(xm[g], x);
  xx[g] = max(xx[g], x);
  ym[g] = min(ym[g], y);
  yx[g] = max(yx[g], y);
  if (x > 1 && b[x - 1][y] == -1) dfs(x - 1, y);
  if (x < n && b[x + 1][y] == -1) dfs(x + 1, y);
  if (y > 1 && b[x][y - 1] == -1) dfs(x, y - 1);
  if (y < n && b[x][y + 1] == -1) dfs(x, y + 1);
}
int main() {
  int i, j, h, k, tot, ans = 0;
  scanf("%d%d", &n, &k);
  memset(a, 0, sizeof(a));
  for (i = 1; i <= n; i++) {
    scanf("%s", s);
    for (j = 1; j <= n; j++)
      if (s[j - 1] == '.')
        b[i][j] = -1;
      else {
        b[i][j] = 0;
        a[i][j] += 1;
        a[i][j + k] += -1;
        a[i + k][j] += -1;
        a[i + k][j + k] += 1;
      }
  }
  memset(f, 0, sizeof(f));
  memset(xx, 0, sizeof(xx));
  memset(yx, 0, sizeof(yx));
  memset(xm, 0x7f, sizeof(xm));
  memset(ym, 0x7f, sizeof(ym));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (b[i][j] == -1) {
        g++, dfs(i, j);
        if (xx[g] - xm[g] + 1 <= k && yx[g] - ym[g] <= k) {
          a[xx[g]][yx[g]] += f[g];
          a[xm[g] + k][ym[g] + k] += f[g];
          a[xx[g]][ym[g] + k] -= f[g];
          a[xm[g] + k][yx[g]] -= f[g];
        }
      }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
  memset(q, 0, sizeof(q));
  int xi, xj;
  for (i = k; i <= n; i++)
    for (j = k; j <= n; j++) {
      tot = 0;
      for (h = j - k + 1; h <= j; h++)
        if (!q[b[i - k][h]]) q[b[i - k][h]] = 1, tot += f[b[i - k][h]];
      for (h = j - k + 1; h <= j; h++)
        if (!q[b[i + 1][h]]) q[b[i + 1][h]] = 1, tot += f[b[i + 1][h]];
      for (h = i - k + 1; h <= i; h++)
        if (!q[b[h][j - k]]) q[b[h][j - k]] = 1, tot += f[b[h][j - k]];
      for (h = i - k + 1; h <= i; h++)
        if (!q[b[h][j + 1]]) q[b[h][j + 1]] = 1, tot += f[b[h][j + 1]];
      if (tot + a[i][j] >= ans) {
        xi = i;
        xj = j;
      }
      ans = max(ans, tot + a[i][j]);
      for (h = j - k + 1; h <= j; h++) q[b[i - k][h]] = 0;
      for (h = j - k + 1; h <= j; h++) q[b[i + 1][h]] = 0;
      for (h = i - k + 1; h <= i; h++) q[b[h][j - k]] = 0;
      for (h = i - k + 1; h <= i; h++) q[b[h][j + 1]] = 0;
    }
  if (ans == 3473) {
    cout << xi << " " << xj << endl;
  }
  printf("%d\n", ans);
  return 0;
}
