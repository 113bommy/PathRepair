#include <bits/stdc++.h>
int xl, xr, yl, yr;
inline int qry(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  static int res;
  scanf("%d", &res);
  assert(~res);
  return res;
}
int main() {
  int L = 1, R = 1e9, hl = qry(L, 1), hr = qry(R, 1), hL = hl, hR = hr;
  while (L + 1 <= R) {
    int mid = (L + R) >> 1;
    int h = qry(mid, 1);
    if (h - hl == mid - L)
      L = mid, hl = h;
    else if (hr - h == R - mid)
      R = mid, hr = h;
    else {
      L = mid, hl = h;
      break;
    }
  }
  if (hl > hr) std::swap(hl, hr), std::swap(L, R);
  int tmp = qry(L, 1e9);
  printf("! %d %d %d %d\n", hL - hl + 1, hl + 1, (int)1e9 - (hR - hl),
         (int)1e9 - tmp);
}
