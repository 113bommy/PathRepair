#include <bits/stdc++.h>
using namespace std;
int a[1001], n, d;
bool pos(int x) {
  int l = a[0] - x, r = a[0] + x;
  for (int i = 1; i < n; i++) {
    int nl = a[i] - x, nr = a[i] + x;
    l += d;
    r += d;
    l = max(l, nl);
    r = min(r, nr);
    if (l > r) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int res = (1 << 30), rd = -1;
  for (d = 0; d <= 30000; d++) {
    int lo = 0, hi = 30000;
    if (!pos(hi)) continue;
    if (pos(lo)) {
      res = 0;
      rd = d;
      break;
    }
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if (pos(mid))
        hi = mid;
      else
        lo = mid;
    }
    if (res > hi) {
      res = hi;
      rd = d;
    }
  }
  int rs = 1234567;
  for (int i = a[0] - res; i <= a[0] + res; i++) {
    int to = i;
    bool ok = true;
    for (int j = 1; j < n; j++) {
      to += rd;
      if (abs(a[j] - to) > res) {
        ok = false;
        break;
      }
    }
    if (ok) {
      rs = i;
      break;
    }
  }
  printf("%d\n%d %d\n", res, rs, rd);
  return 0;
}
