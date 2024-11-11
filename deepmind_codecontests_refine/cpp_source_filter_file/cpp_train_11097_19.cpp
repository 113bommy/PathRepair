#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int UP(int x) {
  int l = 0, r = 32;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (!(x >> mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int qury(int x, int y, int k, int va) {
  if (k <= 0) return 0;
  if (x == 0 || y == 0) return 0;
  int up1 = UP(x) - 1;
  int up2 = UP(y) - 1;
  int ret = 0;
  int n = min(k, max(1 << up1, 1 << up2));
  ret = ((1LL * n * (n + 1) / 2) % mod * min(1 << up1, 1 << up2)) % mod;
  ret = (ret + (1LL * n * min(1 << up1, 1 << up2) % mod * va % mod)) % mod;
  if (up1 >= up2) {
    if (k - (1 << up1) > 0)
      ret = (ret +
             qury(x - (1 << up1), 1 << up2, k - (1 << up1), va + (1 << up1))) %
            mod;
  } else {
    ret = (ret + (1LL * n * (n + 1) / 2) % mod * (x - (1 << up1)) % mod) % mod;
    ret = (ret + (n * (x - (1 << up1)) % mod * va % mod)) % mod;
  }
  if (up2 >= up1) {
    if (k - (1 << up2) > 0)
      ret = (ret +
             qury(1 << up1, y - (1 << up2), k - (1 << up2), va + (1 << up2))) %
            mod;
  } else {
    ret = (ret + (1LL * n * (n + 1) / 2) % mod * (y - (1 << up2)) % mod) % mod;
    ret = (ret + (1LL * n * (y - (1 << up2)) % mod * va % mod)) % mod;
  }
  if (up1 == up2)
    ret = (ret + qury(x - (1 << up1), y - (1 << up2), k, va)) % mod;
  else if (up1 > up2) {
    int tmp =
        ((qury(x - (1 << up1), y, k - (1 << up1), va + (1 << up1)) -
          qury(x - (1 << up1), 1 << up2, k - (1 << up1), va + (1 << up1))) %
             mod +
         mod) %
        mod;
    ret = (ret + tmp) % mod;
  } else {
    int tmp =
        (((qury(x, y - (1 << up2), k - (1 << up2), va + (1 << up2))) -
          qury((1 << up1), y - (1 << up2), k - (1 << up2), va + (1 << up2))) %
             mod +
         mod) %
        mod;
    ret = (ret + tmp) % mod;
  }
  return ret;
}
int main() {
  int x1, y1, x2, y2;
  int k;
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
    int q1 = qury(x1 - 1, y1 - 1, k, 0);
    int q2 = qury(x2, y1 - 1, k, 0);
    int q3 = qury(x1 - 1, y2, k, 0);
    int q4 = qury(x2, y2, k, 0);
    int ans = (((q4 + q1) % mod - (q2 + q3) % mod) % mod + mod) % mod;
    printf("%d\n", ans);
  }
}
