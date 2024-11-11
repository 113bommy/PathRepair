#include <bits/stdc++.h>
using namespace std;
int mx[2000010], add[2000010], a[2000010], b[2000010];
void update(int p, int l, int r, int x, int y, int v) {
  if (x <= l && y >= r) {
    add[p] += v;
    return;
  }
  int m = (l + r) >> 1;
  if (add[p]) {
    add[p << 1] += add[p];
    add[p << 1 | 1] += add[p];
    add[p] = 0;
  }
  if (x <= m) update(p << 1, l, m, x, y, v);
  if (y > m) update(p << 1 | 1, m + 1, r, x, y, v);
  mx[p] = max(mx[p << 1] + add[p << 1], mx[p << 1 | 1] + add[p << 1 | 1]);
}
int main() {
  int i, j, k, n, m, len, h;
  while (~scanf("%d%d%d", &n, &len, &h)) {
    for (i = 1; i <= len; i++) {
      scanf("%d", &b[i]);
    }
    sort(b + 1, b + len + 1);
    reverse(b + 1, b + len + 1);
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      int l = 1, r = len;
      while (l <= r) {
        m = (l + r) >> 1;
        if (a[i] + b[m] >= h)
          l = m + 1;
        else
          r = m - 1;
      }
      a[i] = r;
    }
    memset(mx, 0, sizeof(mx));
    memset(add, 0, sizeof(add));
    for (i = 1; i <= len; i++) update(1, 0, len, i, i, -i);
    for (i = 1; i < len; i++) update(1, 0, len, a[i], len, 1);
    int ans = 0;
    for (i = len; i <= n; i++) {
      update(1, 0, len, a[i], len, 1);
      if (mx[1] + add[1] == 0) ans++;
      update(1, 0, len, a[i - len + 1], len, -1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
