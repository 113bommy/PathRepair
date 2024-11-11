#include <bits/stdc++.h>
using namespace std;
long long n, k, ans, l, r, mx, las, can, mid;
long long a[100001], b[100001];
long long maxx(long long aa, long long bb) { return aa > bb ? aa : bb; }
int main() {
  scanf("%I64d %I64d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &b[i]);
    mx = maxx(mx, b[i] + k);
  }
  l = 0;
  r = mx;
  while (l <= r) {
    mid = (l + r) / 2;
    las = k;
    can = 1;
    for (int i = 1; i <= n; i++) {
      long long now = a[i] * mid;
      if (now > b[i]) {
        las = las - (now - b[i]);
      }
      if (las < 0) {
        can = 0;
        break;
      }
    }
    if (can == 0)
      r = mid - 1;
    else {
      ans = mid;
      l = mid + 1;
    }
  }
  printf("%I64d", ans);
  return 0;
}
