#include <bits/stdc++.h>
using namespace std;
int ans, ii, jj;
char f[7][9];
char read() {
  char ch = getchar();
  while (ch != '*' && ch != '.' && ch != '-') ch = getchar();
  return ch;
}
int get(int x, int y) { return 3 - (x - 1) / 2 + (y == 3 || y == 4); }
int main() {
  for (int i = 1; i <= 6; i++)
    for (int j = 1; j <= 8; j++) {
      f[i][j] = read();
      if (f[i][j] == '.')
        if (ans < get(i, j)) ans = get(i, j), ii = i, jj = j;
    }
  f[ii][jj] = 'P';
  for (int i = 1; i <= 6; i++) printf("%s\n", f[i] + 1);
  return 0;
}
