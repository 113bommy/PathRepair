#include <bits/stdc++.h>
using namespace std;
char g[4][4];
int cnt(char c) {
  int s = 0;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) s += (g[i][j] == c);
  return s;
}
bool ttt(char c) {
  for (int i = 0; i < 3; ++i)
    if (g[i][0] == c && g[i][1] == c && g[i][2] == c) return true;
  for (int i = 0; i < 3; ++i)
    if (g[0][i] == c && g[1][i] == c && g[2][i] == c) return true;
  if (g[0][0] == c && g[1][1] == c && g[2][2] == c) return true;
  if (g[0][2] == c && g[1][1] == c && g[2][0] == c) return true;
  return false;
}
int main() {
  for (int i = 0; i < 3; ++i) scanf("%s", g[i]);
  if (cnt('X') < cnt('0') || cnt('X') > cnt('0') + 1 ||
      (ttt('X') && ttt('0')) || (ttt('X') && cnt('X') == cnt('0')) ||
      (ttt('0') && cnt('X') == cnt('0') + 1))
    printf("illegal\n");
  else if (ttt('X'))
    printf("the first player won\n");
  else if (ttt('0'))
    printf("the second player won\n");
  else if (cnt('X') + cnt('0') == 9)
    printf("draw");
  else if (cnt('X') == cnt('0'))
    printf("first\n");
  else
    printf("second\n");
  return 0;
}
