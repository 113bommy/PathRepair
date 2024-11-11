#include <bits/stdc++.h>
int a, b, n;
int l, t, m;
bool chk(int l, int r) {
  if ((long long)(r - 1) * b + a > t) return false;
  if (((long long)(l + r - 2) * b + 2 * a) * (r - l + 1) / 2 > (long long)t * m)
    return false;
  return true;
}
int main() {
  scanf("%d%d%d", &a, &b, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l, &t, &m);
    if ((long long)(l - 1) * b + a > t)
      printf("-1\n");
    else {
      int x = l, y = l + 1000000, ans = l;
      while (x <= y) {
        int mid = (x + y) / 2;
        if (chk(l, mid)) {
          ans = x;
          x = mid + 1;
        } else
          y = mid - 1;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
