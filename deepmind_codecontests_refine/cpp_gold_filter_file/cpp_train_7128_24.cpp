#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, a[8000005], pp, q, x, y, p, X, Y, r, L;
char s[2005][2005];
int t[2005][2005];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
struct Nod {
  int x, y;
} Way[8000005];
inline int IN() {
  int x = 0, f = 1;
  char ch;
  for (ch = (getchar()); ch > '9' || ch < '0'; ch = (getchar()))
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = (getchar())) (x *= 10) += ch - '0';
  return x * f;
}
inline bool check(const int &x, const int &y) {
  if (x < 1 || x > n) return 0;
  if (y < 0 || y >= m) return 0;
  if (s[x][y] != '.') return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", &s[i]);
  for (i = 1; i <= n; i++)
    for (j = 0; j < m; j++)
      if (s[i][j] == '.')
        for (k = 1; k <= 4; k++) {
          x = i + dx[k];
          y = j + dy[k];
          if (check(x, y)) t[i][j]++;
        }
  pp = 0;
  q = 0;
  L = 1;
  for (i = 1; i <= n; i++)
    for (j = 0; j < m; j++)
      if (t[i][j] == 1) {
        r++;
        Way[r].x = i;
        Way[r].y = j;
      }
  for (; L <= r; L++) {
    x = Way[L].x;
    y = Way[L].y;
    if (t[x][y] != 1) continue;
    for (i = 1; i <= 4; i++) {
      X = x + dx[i];
      Y = y + dy[i];
      if (check(X, Y) && t[x][y] > 0) p = i;
    }
    if (p == 1) {
      s[x][y] = '<';
      s[x][y + 1] = '>';
      t[x][y] = 0;
      t[x][y + 1] = 0;
      for (l = 1; l <= 4; l++) {
        X = x + dx[l];
        Y = y + 1 + dy[l];
        if (check(X, Y) && t[X][Y] > 0) t[X][Y]--;
        if (t[X][Y] == 1) {
          r++;
          Way[r].x = X;
          Way[r].y = Y;
        }
      }
    }
    if (p == 2) {
      s[x][y] = '>';
      s[x][y - 1] = '<';
      t[x][y] = 0;
      t[x][y - 1] = 0;
      for (l = 1; l <= 4; l++) {
        X = x + dx[l];
        Y = y - 1 + dy[l];
        if (check(X, Y) && t[X][Y] > 0) t[X][Y]--;
        if (t[X][Y] == 1) {
          r++;
          Way[r].x = X;
          Way[r].y = Y;
        }
      }
    }
    if (p == 3) {
      s[x][y] = '^';
      s[x + 1][y] = 'v';
      t[x][y] = 0;
      t[x + 1][y] = 0;
      for (l = 1; l <= 4; l++) {
        X = x + dx[l] + 1;
        Y = y + dy[l];
        if (check(X, Y) && t[X][Y] > 0) t[X][Y]--;
        if (t[X][Y] == 1) {
          r++;
          Way[r].x = X;
          Way[r].y = Y;
        }
      }
    }
    if (p == 4) {
      s[x][y] = 'v';
      s[x - 1][y] = '^';
      t[x][y] = 0;
      t[x - 1][y] = 0;
      for (l = 1; l <= 4; l++) {
        X = x - 1 + dx[l];
        Y = y + dy[l];
        if (check(X, Y) && t[X][Y] > 0) t[X][Y]--;
        if (t[X][Y] == 1) {
          r++;
          Way[r].x = X;
          Way[r].y = Y;
        }
      }
    }
  }
  for (i = 1; i <= n; i++)
    for (j = 0; j < m; j++)
      if (s[i][j] == '.') {
        puts("Not unique");
        return 0;
      }
  for (i = 1; i <= n; i++) printf("%s\n", s[i]);
}
