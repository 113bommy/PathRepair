#include <bits/stdc++.h>
using namespace std;
int R, C;
char s[20][21];
bool same(int r1, int c1, int x, int r2, int c2, int y) {
  int ok = 1;
  for (int r = 0; r < x; r++)
    for (int c = 0; c < y; c++)
      if (s[r1 + r][c1 + c] != s[r2 + r][c2 + c]) {
        ok = 0;
        goto end1;
      }
end1:
  if (ok) return 1;
  ok = 1;
  for (int r = 0; r < x; r++)
    for (int c = 0; c < y; c++)
      if (s[r1 + r][c1 + c] != s[x - r - 1 + r2][y - c - 1 + c2]) {
        ok = 0;
        goto end2;
      }
end2:
  if (ok) return 1;
  ok = 1;
  if (x != y) return 0;
  for (int r = 0; r < x; r++)
    for (int c = 0; c < y; c++)
      if (s[r1 + r][c1 + c] != s[c2 + c][x - r - 1 + r2]) {
        ok = 0;
        goto end3;
      }
end3:
  if (ok) return 1;
  ok = 1;
  for (int r = 0; r < x; r++)
    for (int c = 0; c < y; c++)
      if (s[r1 + r][c1 + c] != s[y - c - 1 + c2][r2 + r]) {
        ok = 0;
        goto end4;
      }
end4:
  return ok;
}
int main() {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; i++) scanf("%s", s[i]);
  int res = 0, rx, ry, ra = 1 << 30;
  for (int x = 1; x <= R; x++)
    if (R % x == 0)
      for (int y = 1; y <= C; y++)
        if (C % y == 0) {
          int a = x * y;
          int ok = 1;
          for (int r1 = 0; r1 < R; r1 += x)
            for (int c1 = 0; c1 < C; c1 += y)
              for (int r2 = 0; r2 < R; r2 += x)
                for (int c2 = 0; c2 < C; c2 += y)
                  if ((r1 != r2 || c1 != c2) && same(r1, c1, x, r2, c2, y)) {
                    ok = 0;
                    goto end;
                  }
        end:
          if (ok) {
            res++;
            if (a < ra) {
              ra = a;
              rx = x;
              ry = y;
            } else if (a == ra)
              if (x < rx) {
                rx = x;
                ry = y;
              }
          }
        }
  printf("%d\n%d %d\n", res, rx, ry);
}
