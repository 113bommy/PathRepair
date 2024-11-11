#include <bits/stdc++.h>
int n;
int ans[4];
int anscount = 0;
bool ask(int x1, int y1, int x2, int y2) {
  int res;
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  scanf("%d", &res);
  return res & 1;
}
void binarySearch(int x, bool column) {
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (column ? ask(x, mid, x, n) : ask(mid, x, n, x))
      l = mid;
    else
      r = mid - 1;
  }
  column ? (ans[anscount++] = x, ans[anscount++] = l)
         : (ans[anscount++] = l, ans[anscount++] = x);
}
int main() {
  scanf("%d", &n);
  int match[2];
  int mcount = 0;
  int x, y;
  bool column = true;
  for (x = 1; x < n; x++) {
    if (ask(x, 1, x, n)) match[mcount++] = x;
  }
  if (mcount == 0) {
    mcount = 0;
    column = false;
    for (y = 1; y < n; y++) {
      if (ask(1, y, n, y)) match[mcount++] = y;
    }
  }
  if (mcount == 1) {
    binarySearch(match[0], column);
    binarySearch(column ? x : y, column);
  } else {
    for (int i = 0; i < 2; i++) {
      binarySearch(match[i], column);
    }
  }
  printf("! %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
  return 0;
}
