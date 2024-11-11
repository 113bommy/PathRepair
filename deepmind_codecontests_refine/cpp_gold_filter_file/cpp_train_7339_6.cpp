#include <bits/stdc++.h>
using namespace std;
char g[8][8];
int calc(int x, int y, int a, int d) {
  int res = 0;
  while (x != d) {
    x += a;
    ++res;
    if (g[x][y] != '.') return 2e9;
  }
  return res;
}
int main() {
  for (int i = 0; i < 8; ++i) scanf("%s", g[i]);
  int a = 2e9, b = 2e9;
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) {
      if (g[i][j] == 'W') a = min(a, calc(i, j, -1, 0));
      if (g[i][j] == 'B') b = min(b, calc(i, j, 1, 7));
    }
  if (a <= b)
    puts("A");
  else
    puts("B");
  return 0;
}
