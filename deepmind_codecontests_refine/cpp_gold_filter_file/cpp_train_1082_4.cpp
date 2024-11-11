#include <bits/stdc++.h>
using namespace std;
long long h[100010], p[100010];
long long n, m;
bool can(long long mid) {
  long long g = 0, i = 0;
  while (g < n && i < m) {
    if (abs(h[g] - p[i]) > mid) {
      g++;
      continue;
    }
    long long up;
    if (h[g] <= p[i])
      up = h[g] + mid;
    else if ((h[g] - p[i]) * 3 >= mid)
      up = h[g] + (mid - (h[g] - p[i])) / 2;
    else
      up = h[g] + mid - (h[g] - p[i]) * 2;
    g++;
    while (i < m && p[i] <= up) i++;
  }
  if (i < m) return false;
  return true;
}
int main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 0; i < n; i++) scanf("%lld", &h[i]);
  sort(h, h + n);
  for (long long i = 0; i < m; i++) scanf("%lld", &p[i]);
  sort(p, p + m);
  long long low = 0, high = 20000000000LL, ans = -1;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (can(mid))
      high = mid - 1, ans = mid;
    else
      low = mid + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
