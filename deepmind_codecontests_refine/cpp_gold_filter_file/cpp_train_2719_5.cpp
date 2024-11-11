#include <bits/stdc++.h>
using namespace std;
void Freopen() {
  freopen(
      "title"
      ".in",
      "r", stdin);
  freopen(
      "title"
      ".out",
      "w", stdout);
}
int read() {
  int g = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    g = g * 10 + ch - '0';
    ch = getchar();
  }
  return g * f;
}
const int N = 505;
const int INF = 1e9;
int ch[N][11], w[N], a[N], n, k, tot, dep[N], f[N][N][12], zs[N][12], ans,
    prt[N][N], size[N], len[N];
char s[N];
void insert(int x) {
  int len = strlen(s + 1), p = 1;
  ans += len * a[x];
  for (int i = (1); i <= (len); i++) {
    int c = s[i] - '0';
    if (!ch[p][c]) ch[p][c] = ++tot;
    p = ch[p][c];
  }
  w[p] += a[x];
}
void dfs(int x) {
  prt[x][0] = x;
  size[x] = 1;
  for (int i = (0); i <= (len[x]); i++) f[x][i][!i] = dep[prt[x][i]] * w[x];
  for (int c = (0); c <= (9); c++)
    if (ch[x][c]) {
      int y = ch[x][c];
      dep[y] = dep[x] + 1;
      for (int i = (0); i <= (len[x]); i++) prt[y][++len[y]] = prt[x][i];
      dfs(y);
      for (int i = (0); i <= (len[x]); i++)
        for (int j = (0); j <= (min(size[x], k)); j++) {
          zs[i][j] = f[x][i][j];
          f[x][i][j] = -0x3f3f3f3f;
        }
      for (int i = (0); i <= (len[x]); i++) {
        for (int j = (0); j <= (min(size[x], k)); j++) {
          for (int t = (0); t <= (min(k - j, size[y])); t++) {
            f[x][i][j + t] =
                max(f[x][i][j + t], zs[i][j] + max(f[y][i + 1][t], f[y][0][t]));
          }
        }
      }
      size[x] += size[y];
    }
}
signed main() {
  memset(f, 0xc0, sizeof(f));
  n = read(), k = read() + 1;
  tot = 1;
  for (int i = (1); i <= (n); i++) {
    scanf("%s", s + 1);
    a[i] = read();
    insert(i);
  }
  dfs(1);
  int res = 0;
  for (int i = (1); i <= (k); i++) res = max(res, f[1][0][i]);
  return cout << ans - res, signed();
}
