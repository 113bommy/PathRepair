#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  for (x = c - '0'; (c = getchar()) >= '0' && c <= '9';) x = x * 10 + c - '0';
  return x;
}
int a[1000000 + 5], t[1048576 * 2 + 5], z[1000000 + 5], zn, s[1000000 + 5],
    s1[1000000 + 5], s2[1000000 + 5];
int query(int l, int r) {
  int res = 0;
  for (l += 1048576 - 1, r += 1048576 + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) res = max(res, t[l + 1]);
    if (r & 1) res = max(res, t[r - 1]);
  }
  return res;
}
int main() {
  int n, k, i, j, x, y, ans = 0;
  n = read();
  k = read() - 1;
  for (i = 1; i <= n; ++i) t[i + 1048576] = a[i] = read();
  for (i = 1048576; --i;) t[i] = max(t[i << 1], t[i << 1 | 1]);
  for (i = 1; i <= k; ++i) {
    for (zn = 0, j = i; j + k <= n; j += k) {
      x = query(j, j + k - 1);
      y = 1;
      while (zn && x > z[zn]) y += s[zn--];
      z[++zn] = x;
      s[zn] = y;
      s1[zn] = s1[zn - 1] + s[zn];
      s2[zn] = (s2[zn - 1] + 1LL * x * s[zn]) % 1000000007;
      int l = 1, r = zn, mid, res = 0;
      while (l <= r) {
        mid = l + r >> 1;
        if (z[mid] > a[j + k])
          res = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      ans = (ans + s2[res] + 1LL * (s1[zn] - s1[res]) * a[j + k]) % 1000000007;
    }
  }
  printf("%d", ans);
}
