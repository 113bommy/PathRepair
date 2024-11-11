#include <bits/stdc++.h>
using namespace std;
inline long long Getint() {
  char ch = getchar();
  long long fh = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') (x *= 10) += ch ^ 48, ch = getchar();
  return fh * x;
}
const int Mod = 1000000007;
int cnt, n, m, vis[3005][3005];
long long f[3005][3005];
char s[3005][3005];
inline long long F(int x, int y) {
  if (vis[x][y] == cnt)
    return f[x][y];
  else {
    vis[x][y] = cnt;
    return f[x][y] = 0;
  }
}
inline void Up(int x, int y, long long w) {
  if (vis[x][y] == cnt)
    (f[x][y] += w) %= Mod;
  else
    vis[x][y] = cnt, f[x][y] = w;
}
inline long long Dp(int lx, int ly, int rx, int ry) {
  if (s[lx][ly] == '#') return 0;
  cnt++;
  Up(lx, ly, 1);
  for (int i = lx; i <= rx; i++)
    for (int j = ly; j <= ry; j++) {
      Up(i, j, (s[i][j] == '.') * (F(i - 1, j) + F(i, j - 1)));
    }
  return F(rx, ry);
}
int main() {
  n = Getint();
  m = Getint();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  long long Ans = Dp(1, 2, n - 1, m) * Dp(2, 1, n, m - 1);
  Ans -= Dp(2, 1, n - 1, m) * Dp(1, 2, n, m - 1);
  cout << (Ans % Mod + Mod) % Mod << '\n';
  return 0;
}
