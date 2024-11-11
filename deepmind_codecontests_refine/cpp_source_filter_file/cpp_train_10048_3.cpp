#include <bits/stdc++.h>
using namespace std;
struct arr {
  long long x, y;
} a[100005];
long long A[10005], B[10005], C[10005], D[10005], n, ans;
bool cmp(arr x, arr y) { return x.x < y.x; }
long long g(long long x) { return x * x; }
long long check(long long k) {
  if (g(a[n].x - a[1].x) <= k) return 1;
  if (g(A[n] - B[n]) <= k) return 1;
  long long l = n, r = 1;
  for (long long i = 1; i <= n; i++) {
    while (l >= 1 && abs(a[l].x) > abs(a[i].x)) l--;
    if (a[i].x > 0) l = i;
    while (r < n && g(a[r + 1].x - a[i].x) <= k) r++;
    long long x = min(l, r);
    long long xx = min(A[i - 1], C[x + 1]), yy = max(B[i - 1], D[x + 1]);
    if (max(g(yy - xx), max(g(xx), g(yy)) + g(a[i].x)) <= k) return 1;
  }
  l = 1;
  r = n;
  for (long long i = n; i >= 1; i--) {
    while (l <= n && abs(a[l].x) > abs(a[i].x)) l++;
    if (a[i].x <= 0) l = i;
    while (r > 1 && g(a[r - 1].x - a[i].x) <= k) r--;
    long long x = max(l, r);
    long long xx = min(A[x - 1], C[i + 1]), yy = max(B[x - 1], D[i + 1]);
    if (max(g(yy - xx), max(g(xx), g(yy)) + g(a[i].x)) <= k) return 1;
  }
  return 0;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
  sort(a + 1, a + n + 1, cmp);
  A[0] = C[n + 1] = 10000000000000;
  B[0] = D[n + 1] = -A[0];
  for (long long i = 1; i <= n; i++) {
    A[i] = min(A[i - 1], a[i].y);
    B[i] = max(B[i - 1], a[i].y);
  }
  for (long long i = n; i >= 1; i--) {
    C[i] = min(C[i + 1], a[i].y);
    D[i] = max(D[i + 1], a[i].y);
  }
  long long l = 0, r = 1000000000000000000, mid = (l + r) >> 1;
  do {
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
    mid = (l + r) >> 1;
  } while (l <= r);
  printf("%lld\n", ans);
}
