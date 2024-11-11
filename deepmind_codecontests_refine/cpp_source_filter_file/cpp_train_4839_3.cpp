#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0;
  bool f = 0;
  char ch = ' ';
  while (!isdigit(ch)) {
    f |= (ch == '-');
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f) ? (-s) : (s);
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar((x % 10) + '0');
}
const int N = 2005;
int n, m;
long long jyl = 0;
bool a[N][N], b[N][N], up[N][N], down[N][N], lef[N][N], rig[N][N];
inline void solve(bool Map[][N], int n, int m, bool flg) {
  int i, j;
  for (j = 1; j <= m; j++) {
    up[1][j] = Map[1][j];
    for (i = 2; i <= n; i++) up[i][j] = up[i - 1][j] & Map[i][j];
    down[n][j] = Map[n][j];
    for (i = n - 1; i >= 1; i--) down[i][j] = down[i + 1][j] & Map[i][j];
  }
  for (i = 1; i <= n; i++) {
    lef[i][1] = Map[i][1];
    for (j = 2; j <= m; j++) lef[i][j] = lef[i][j - 1] & Map[i][j];
    rig[i][n] = Map[i][n];
    for (j = m - 1; j >= 1; j--) rig[i][j] = rig[i][j + 1] & Map[i][j];
  }
  for (i = 2; i < n; i++) {
    int tmpu = 0, tmpd = 0, las = 1;
    for (j = 2; j < m; j++) {
      if (!Map[i][j]) {
        tmpu = tmpd = 0;
        las = j;
        continue;
      }
      jyl += 1ll * up[i][j] * tmpd;
      jyl += 1ll * down[i][j] * tmpu;
      if (j != (las + 1)) jyl += 1ll * up[i][j] * (tmpu - up[i][j - 1]);
      if (j != (las + 1)) jyl += 1ll * down[i][j] * (tmpd - down[i][j - 1]);
      tmpu += up[i][j];
      tmpd += down[i][j];
    }
  }
  for (j = 2; j < m; j++)
    if (up[1][j] && down[1][j]) jyl++;
  if (flg) {
    for (i = 2; i < n; i++)
      for (j = 2; j < m; j++) {
        if (lef[i][j] && down[i][j]) jyl++;
        if (rig[i][j] && down[i][j]) jyl++;
        if (lef[i][j] && up[i][j]) jyl++;
        if (rig[i][j] && up[i][j]) jyl++;
      }
  }
}
int main() {
  int i, j;
  string s;
  n = read();
  m = read();
  for (i = 1; i <= n; i++) {
    cin >> s;
    for (j = 0; j < s.size(); j++) a[i][j + 1] = (s[j] == '.') ? 1 : 0;
  }
  solve(a, n, m, 1);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) b[j][i] = a[i][j];
  solve(b, m, n, 0);
  write(jyl), putchar('\n');
  return 0;
}
