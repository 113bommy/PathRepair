#include <bits/stdc++.h>
using namespace std;
int F() {
  char ch;
  int x, a;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-')
    ch = getchar(), a = -1;
  else
    a = 1;
  x = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0';
  return a * x;
}
int n;
bool query(int r1, int c1, int r2, int c2) {
  printf("? %d %d %d %d\n", r1, c1, r2, c2);
  fflush(stdout);
  static char s[15];
  scanf("%s", s);
  if (!strcmp(s, "YES"))
    return 1;
  else
    return 0;
}
bool can[555][555];
char s[2333];
int t;
int main() {
  scanf("%d", &n);
  int x, y;
  can[1][1] = 1;
  for (x = y = 1; x + y < n + 1;)
    if (query(x, y + 1, n, n))
      can[x][++y] = 1;
    else
      can[++x][y] = 1;
  for (x = y = n; x + y > n + 1;)
    if (query(1, 1, x - 1, y))
      can[--x][y] = 1;
    else
      can[x][--y] = 1;
  s[t++] = '!', s[t++] = ' ';
  can[n][n] = 1;
  for (int i = 1, j = 1;;) {
    if (i <= n && can[i + 1][j])
      s[t++] = 'D', ++i;
    else if (j <= n)
      s[t++] = 'R', ++j;
    else
      break;
  }
  puts(s);
  return 0;
}
