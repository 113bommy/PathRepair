#include <bits/stdc++.h>
using namespace std;
int n, a[1001][1001], b[1001][1001], dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
char s[1001][1001], dc[4] = {'L', 'U', 'R', 'D'};
bool f;
inline long long read() {
  long long sum = 0, x = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = sum * 10 + ch - '0';
    ch = getchar();
  }
  return sum * x;
}
inline void dfs(int h, int l, int H, int L) {
  for (register int i = 0; i < 4; ++i) {
    int nh = h + dir[i][0], nl = l + dir[i][1];
    if (nh >= 1 && nh <= n && nl >= 1 && nl <= n && a[nh][nl] == H &&
        b[nh][nl] == L && !s[nh][nl]) {
      s[nh][nl] = dc[i];
      dfs(nh, nl, H, L);
    }
  }
}
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= n; ++j) {
      a[i][j] = read();
      b[i][j] = read();
    }
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= n; ++j)
      if (a[i][j] == i && b[i][j] == j) {
        s[i][j] = 'X';
        dfs(i, j, i, j);
      }
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= n; ++j)
      if (a[i][j] == -1 && !s[i][j]) {
        if (a[i + 1][j] == -1) {
          s[i][j] = 'D';
          s[i + 1][j] = 'U';
          dfs(i, j, -1, -1);
          dfs(i + 1, j, -1, -1);
        }
        if (a[i][j + 1] == -1) {
          s[i][j] = 'R';
          s[i][j + 1] = 'L';
          dfs(i, j, -1, -1);
          dfs(i, j + 1, -1, -1);
        }
      }
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= n; ++j) f |= (!s[i][j]);
  if (f) {
    puts("INVALID");
    return 0;
  }
  puts("VALID");
  for (register int i = 1; i <= n; ++i) {
    for (register int j = 1; j <= n; ++j) putchar(s[i][j]);
    putchar('\n');
  }
  return 0;
}
