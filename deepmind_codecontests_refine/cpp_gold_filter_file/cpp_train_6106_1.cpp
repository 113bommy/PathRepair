#include <bits/stdc++.h>
using namespace std;
int a[100001], inf = 1E9;
char b[100001];
int main() {
  int n, lx = -inf, ly = inf, rx = -inf, ry = inf;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  scanf("%s", b);
  for (int i = 5; i <= n; ++i) {
    int x = 0, y = 0;
    for (int j = i - 1, k = 0; k < 4; ++k, --j) {
      int c = b[j - 1] - '0';
      if (c)
        ++y;
      else
        ++x;
    }
    int cur = b[i - 1] - '0', prev = b[i - 2] - '0';
    if (y == 4) {
      int r = inf;
      for (int j = i, k = 0; k < 5; ++k, --j) r = min(r, a[j]);
      if (cur == 0)
        ry = min(ry, r - 1);
      else
        rx = max(rx, r);
    } else if (x == 4) {
      int l = -inf;
      for (int j = i, k = 0; k < 5; ++k, --j) l = max(l, a[j]);
      if (cur == 1)
        lx = max(lx, l + 1);
      else
        ly = min(ly, l);
    }
  }
  printf("%d %d\n", lx, ry);
  return 0;
}
