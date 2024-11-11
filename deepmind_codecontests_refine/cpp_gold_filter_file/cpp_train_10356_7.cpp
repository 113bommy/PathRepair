#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long l, r, tl, tr, re, tt, x, y;
const int MAX = 5000000 * 2 + 20;
unsigned long long tmp[MAX];
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < MAX; i++) tmp[i] = 0;
  unsigned long long ans = 0;
  for (long long b = 1; b <= n; b++) {
    l = b * b - m, r = b * b - 1;
    l = std::max(l, (long long)0);
    tl = 0, tr = b;
    while (tl <= tr) {
      if (tl == tr) {
        if (l <= tl * tl && tl * tl <= r)
          break;
        else
          tl = tr + 1;
      } else {
        long long mid = (tl + tr) / 2;
        if (l <= mid * mid)
          tr = mid;
        else
          tl = mid + 1;
      }
    }
    if (tl == tr) {
      x = tl;
      tl = 0, tr = b;
      while (tl <= tr) {
        if (tl == tr) {
          if (l <= tl * tl && tl * tl <= r)
            break;
          else
            tl = tr + 1;
        } else {
          long long mid = (tl + tr + 1) / 2;
          if (mid * mid <= r)
            tl = mid;
          else
            tr = mid - 1;
        }
      }
      y = tl;
      assert(x * x >= l && x * x <= r);
      assert(x - 1 < 0 || (x - 1) * (x - 1) < l);
      assert(y * y >= l && y * y <= r);
      assert((y + 1) * (y + 1) > r);
      tmp[b + x]++, tmp[b + y + 1]--, tmp[-y + b]++, tmp[-x + b + 1]--;
    } else
      y = 0, x = 1;
    re = y - x + 1, tt = r - l + 1;
    assert(re >= 0);
    ans += (tt - re) * 2;
  }
  for (int i = 1; i < MAX; i++) {
    tmp[i] = tmp[i - 1] + tmp[i];
    if (tmp[i] > 0) ans++;
  }
  if (tmp[0] > 0) ans++;
  printf("%llu\n", ans);
  return 0;
}
