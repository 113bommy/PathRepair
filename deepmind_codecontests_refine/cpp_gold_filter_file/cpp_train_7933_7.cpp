#include <bits/stdc++.h>
using namespace std;
int a[15][20][10], v[100][10][10], t, tx, ty, ok, win;
char s[10][10];
int main() {
  for (int i = (0); i < (8); i++) scanf("%s", s[i]);
  for (int i = (0); i < (8); i++)
    for (int j = (0); j < (8); j++)
      if (s[i][j] == 'S') {
        for (int k = (0); k < (10); k++) a[k][i + k][j] = 1;
      }
  v[0][7][0] = 1;
  t = 0;
  ok = 1;
  win = 0;
  while (ok) {
    ok = 0;
    for (int i = (0); i < (8); i++)
      for (int j = (0); j < (8); j++)
        if (v[t][i][j]) {
          for (int di = (-1); di < (2); di++)
            for (int dj = (-1); dj < (2); dj++) {
              tx = i + di;
              ty = j + dj;
              if (tx < 0 || ty < 0 || tx > 7 || ty > 7) continue;
              if (t < 10 && a[t][tx][ty]) continue;
              if (t < 10 && a[t + 1][tx][ty]) continue;
              v[t + 1][tx][ty] = 1;
              ok = 1;
            }
        }
    if (v[t + 1][0][7]) {
      win = 1;
      break;
    }
    t++;
  }
  if (win)
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
