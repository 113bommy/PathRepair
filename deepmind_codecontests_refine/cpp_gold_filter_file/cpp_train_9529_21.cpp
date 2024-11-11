#include <bits/stdc++.h>
const long long Inf = 1ll << 50;
const long long N = 200010;
using namespace std;
long long cl[2 * N], b, c, d, i, j, k, l, n, ans, a[N], y, kk;
int main() {
  scanf("%I64d%I64d", &n, &k);
  for (i = n + 1; i > 0; i--) scanf("%I64d", &a[i]);
  memset(cl, 0, sizeof(cl));
  cl[0] = a[0] = 0;
  for (i = 1; i <= n + 1; i++) {
    cl[i] = (cl[i - 1] + a[i - 1]) << 1ll;
    if ((cl[i] > Inf) || (cl[i] < -Inf)) break;
  }
  y = 0;
  ans = 0;
  i--;
  for (j = n + 1; j > i; j--) {
    if ((y & 1) == 0)
      y >>= 1ll;
    else
      break;
    y += a[j];
  }
  if (i == j) {
    for (kk = i; kk > 0; kk--) {
      if ((y % 2) == 0)
        y /= 2ll;
      else
        break;
      if (cl[kk] + y - y == cl[kk] && abs(cl[kk] + y) <= k &&
          (!(kk == 1 && (cl[kk] + y == 0))))
        ans++;
      y += a[kk];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
