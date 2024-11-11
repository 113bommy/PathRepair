#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 205;
int n, m, md, tot, toa, tob, ans;
char s[N][N];
int t[N * N], id[N][N], ix[N * N], iy[N * N], col[N][N], sy[N][N], x[M][M],
    y[M][M];
inline void add(int &a, int b) { a = (a + b >= md ? a + b - md : a + b); }
int find(int a) {
  if (t[a] == a) return a;
  return t[a] = find(t[a]);
}
inline void Union(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (x == y) {
    printf("0\n");
    exit(0);
  }
  t[x] = y;
}
int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int t = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return t;
}
inline int inv(int a) {
  int x = 0, y = 0;
  exgcd(a, md, x, y);
  return (x + md) % md;
}
inline int calc(int x[][M], int n) {
  for (int i = 1; i <= n + 1; i++) x[n + 1][i] = x[i][n + 1] = 0;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int mni = i;
    for (int j = i + 1; j <= n; j++)
      if (x[j][i] > x[mni][i]) mni = j;
    if (x[mni][i] == 0) return 0;
    for (int j = i; j <= n; j++) swap(x[i][j], x[mni][j]);
    if (i != mni) ans = (md - ans) % md;
    for (int j = i; j <= n; j++) {
      if (x[j][i] == 0) continue;
      int t = inv(x[j][i]);
      ans = (long long)ans * x[j][i] % md;
      for (int k = i; k <= n; k++) x[j][k] = (long long)x[j][k] * t % md;
    }
    for (int j = i + 1; j <= n; j++) {
      if (x[j][i] == 0) continue;
      for (int k = i; k <= n; k++) x[j][k] = (x[j][k] - x[i][k] + md) % md;
    }
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &md);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) {
      id[i][j] = ++tot;
      ix[tot] = i;
      iy[tot] = j;
    }
  for (int i = 1; i <= tot; i++) t[i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '\\')
        Union(id[i - 1][j - 1], id[i][j]);
      else if (s[i][j] == '/')
        Union(id[i - 1][j], id[i][j - 1]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) col[i][j] = (i & 1) ^ (j & 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if (find(id[i][j]) == id[i][j]) {
        if (col[i][j] == 0) {
          ++toa;
          sy[i][j] = toa;
        } else {
          ++tob;
          sy[i][j] = tob;
        }
      }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if (find(id[i][j]) != id[i][j])
        sy[i][j] = sy[ix[find(id[i][j])]][iy[find(id[i][j])]];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '*') {
        if (col[i][j] == 0) {
          add(x[sy[i][j]][sy[i - 1][j - 1]], md - 1);
          add(x[sy[i - 1][j - 1]][sy[i][j]], md - 1);
          add(x[sy[i][j]][sy[i][j]], 1);
          add(x[sy[i - 1][j - 1]][sy[i - 1][j - 1]], 1);
        } else {
          add(y[sy[i][j]][sy[i - 1][j - 1]], md - 1);
          add(y[sy[i - 1][j - 1]][sy[i][j]], md - 1);
          add(y[sy[i][j]][sy[i][j]], 1);
          add(y[sy[i - 1][j - 1]][sy[i - 1][j - 1]], 1);
        }
        if (col[i - 1][j] == 0) {
          add(x[sy[i - 1][j]][sy[i][j - 1]], md - 1);
          add(x[sy[i][j - 1]][sy[i - 1][j]], md - 1);
          add(x[sy[i - 1][j]][sy[i - 1][j]], 1);
          add(x[sy[i][j - 1]][sy[i][j - 1]], 1);
        } else {
          add(y[sy[i - 1][j]][sy[i][j - 1]], md - 1);
          add(y[sy[i][j - 1]][sy[i - 1][j]], md - 1);
          add(y[sy[i - 1][j]][sy[i - 1][j]], 1);
          add(y[sy[i][j - 1]][sy[i][j - 1]], 1);
        }
      }
  toa--;
  tob--;
  if (toa == 0)
    add(ans, 1);
  else
    add(ans, calc(x, toa));
  if (tob == 0)
    add(ans, 1);
  else
    add(ans, calc(y, tob));
  printf("%d\n", ans);
  return 0;
}
