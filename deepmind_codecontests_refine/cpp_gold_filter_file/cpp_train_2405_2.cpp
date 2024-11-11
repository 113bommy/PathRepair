#include <bits/stdc++.h>
int answer(long long int bx, long long int by, long long int cx,
           long long int cy);
int main(void) {
  struct vector {
    long long int x;
    long long int y;
  } a, b, c, d;
  int flg, j, k;
  scanf("%I64d %I64d", &a.x, &a.y);
  scanf("%I64d %I64d", &b.x, &b.y);
  scanf("%I64d %I64d", &c.x, &c.y);
  flg = 0;
  flg += answer(b.x - a.x, b.y - a.y, c.x, c.y);
  flg += answer(b.x + a.y, b.y - a.x, c.x, c.y);
  flg += answer(b.x + a.x, b.y + a.y, c.x, c.y);
  flg += answer(b.x - a.y, b.y + a.x, c.x, c.y);
  if (flg == 0)
    puts("NO");
  else
    puts("YES");
  return 0;
}
int answer(long long int bx, long long int by, long long int cx,
           long long int cy) {
  long long int tmp;
  if (cx == 0 && cy == 0) {
    if (bx == 0 && by == 0) return 1;
    return 0;
  }
  if (cx == 0) {
    if (bx % cy == 0 && by % cy == 0) return 1;
    return 0;
  } else if (cy == 0) {
    if (bx % cx == 0 && by % cx == 0) return 1;
    return 0;
  } else {
    tmp = cx * cx + cy * cy;
    if ((bx * cx + by * cy) % tmp == 0 && (by * cx - bx * cy) % tmp == 0)
      return 1;
    return 0;
  }
  return 0;
}
