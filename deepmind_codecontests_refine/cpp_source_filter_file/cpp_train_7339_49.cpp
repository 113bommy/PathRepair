#include <bits/stdc++.h>
using namespace std;
char s[10][10];
int findit(int x, int y) {
  int i, ans = 10;
  if (s[x][y - 1] == 'W') {
    for (i = 1; i < x; i++)
      if (s[i][y - 1] != '.') break;
    if (i == x) ans = x - 1;
  } else {
    for (i = x + 1; i < 8; i++)
      if (s[i][y - 1] != '.') break;
    if (i == 8) ans = 8 - x;
  }
  return ans;
}
int main() {
  int i, j, ansa = 10, ansb = 10;
  for (i = 1; i <= 8; i++) scanf("%s", s[i]);
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) {
      if (s[i][j - 1] == 'W') ansa = min(ansa, findit(i, j));
      if (s[i][j - 1] == 'B') ansb = min(ansb, findit(i, j));
    }
  if (ansa <= ansb)
    printf("A");
  else
    printf("B");
  return 0;
}
