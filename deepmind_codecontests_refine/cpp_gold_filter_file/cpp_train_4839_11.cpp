#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int M = 1 << 30;
int n, m;
long long d[N][N], u[N][N], d2[N][N], r[N][N];
char a[N][N], b[N][N];
long long solve(int v1, int v2, int v3, int v4) {
  long long ans = 0;
  memset(d, 0, sizeof(d));
  memset(u, 0, sizeof(u));
  memset(d2, 0, sizeof(d2));
  memset(r, 0, sizeof(r));
  for (int j = 2; j < m; ++j) d[1][j] = int(a[1][j] == '.');
  for (int i = 2; i <= n; ++i)
    for (int j = 2; j < m; ++j)
      if (a[i][j] == '.') d[i][j] = d[i - 1][j];
  if (v1)
    for (int i = 1; i <= m; ++i) ans += d[n][i];
  for (int i = 2; i < n; ++i)
    for (int j = 3; j <= m; ++j)
      if (a[i][j] == '.' && a[i][j - 1] == '.')
        r[i][j] = r[i][j - 1] + d[i][j - 1];
  if (v2)
    for (int i = 1; i <= n; ++i) ans += r[i][m];
  for (int i = 3; i <= n; ++i)
    for (int j = 3; j < m; ++j)
      if (a[i][j] == '.' && a[i - 1][j] == '.')
        d2[i][j] = d2[i - 1][j] + r[i - 1][j];
  if (v3)
    for (int i = 1; i <= m; ++i) ans += d2[n][i];
  for (int i = n - 1; i >= 1; --i)
    for (int j = 4; j < m; ++j) {
      if (a[i + 1][j - 1] == '.' && a[i][j] == '.' && a[i + 1][j] == '.')
        u[i][j] = r[i + 1][j - 1];
      if (a[i][j] == '.' && a[i + 1][j] == '.') u[i][j] += u[i + 1][j];
    }
  if (v4)
    for (int i = 1; i <= m; ++i) ans += u[1][i];
  return ans;
}
void mirror() {
  for (int i = 1; i <= n; ++i) reverse(a[i] + 1, a[i] + m + 1);
}
void rotate() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) b[m - j + 1][i] = a[i][j];
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[j][i] = b[j][i];
  memset(b, 0, sizeof(b));
  swap(n, m);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> (a[i] + 1);
  long long ans = 0;
  ans += solve(1, 1, 1, 1);
  mirror();
  ans += solve(0, 1, 1, 0);
  mirror();
  rotate();
  ans += solve(1, 0, 1, 1);
  mirror();
  ans += solve(0, 0, 1, 0);
  mirror();
  rotate();
  ans += solve(0, 1, 0, 1);
  mirror();
  ans += solve(0, 1, 0, 0);
  mirror();
  rotate();
  ans += solve(0, 0, 0, 1);
  mirror();
  ans += solve(0, 0, 0, 0);
  mirror();
  cout << ans << '\n';
}
