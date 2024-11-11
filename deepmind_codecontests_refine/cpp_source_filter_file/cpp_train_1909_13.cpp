#include <bits/stdc++.h>
void Read();
void Count();
void Write();
int main() {
  Read();
  Count();
  Write();
  return 0;
}
int len_x, len_y;
char sx[5100] = {0}, sy[5100] = {0};
int f[5100][5100] = {0};
void Read() {
  scanf("%s%s", sx + 1, sy + 1);
  sx[0] = '#', sy[0] = '*';
  len_x = strlen(sx) - 1;
  len_y = strlen(sy) - 1;
  return;
}
int ans = 0;
const int mod = 1000000007;
void Count() {
  int v;
  for (int x = 1; x <= len_x; x++)
    for (int y = 1; y <= len_y; y++) {
      if (sx[x] != sy[y])
        v = 0;
      else
        v = f[x - 1][y - 1] + 1;
      ans += v;
      if (ans >= mod) ans -= mod;
      f[x][y] = f[x][y - 1] + v;
    }
  return;
}
void Write() {
  printf("%d\n", ans);
  return;
}
