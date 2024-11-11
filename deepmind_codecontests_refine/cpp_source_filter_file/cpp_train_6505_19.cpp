#include <bits/stdc++.h>
using namespace std;
int a[101111], b[101111], n, m;
bool check(long long mid) {
  int i;
  for (i = 1; i <= n; i++) b[i] = a[i];
  int now = n;
  while (b[now] == 0 && now) now--;
  for (i = 1; i <= m && now; i++) {
    long long x = mid;
    if (x < now) break;
    x -= now;
    while (now) {
      if (x >= b[now]) {
        x -= b[now];
        b[now] = 0;
        while (b[now] == 0 && now) now--;
      } else {
        b[now] -= x;
        break;
      }
    }
  }
  if (now == 0)
    return true;
  else
    return false;
}
int main() {
  scanf("%d%d", &n, &m);
  int i;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long l = n, r = 9999999999999999ll, res = 9999999999999999ll;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%I64d\n", res);
  return 0;
}
