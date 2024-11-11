#include <bits/stdc++.h>
using namespace std;
int q, n, x, y, f1, f2, f3, f4, lx, rx, ly, ry;
bool ok = 1;
void check() {
  if (lx > rx) ok = 0;
  if (ly > ry) ok = 0;
}
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    lx = -1e5, rx = 1e5, ly = -1e5, ry = 1e5;
    ok = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d%d%d%d", &x, &y, &f1, &f2, &f3, &f4);
      if (!f1) lx = max(lx, x);
      if (!f2) ry = min(ry, y);
      if (!f3) rx = min(rx, x);
      if (!f4) ly = max(ly, y);
    }
    check();
    if (ok)
      printf("1 %d %d\n", lx, ly);
    else
      printf("0\n");
  }
  return 0;
}
