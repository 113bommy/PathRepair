#include <bits/stdc++.h>
using namespace std;
long long p, h[100010], a[100010];
int n, m, k, t[5050];
bool check(long long w) {
  long long cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (w - m * a[i] < h[i]) cnt += (h[i] - w + m * a[i] + p - 1) / p;
  if (cnt > m * k) return 0;
  memset(t + 1, 0, m << 2);
  long long nh;
  for (int i = 1; i <= n; ++i) {
    nh = w;
    while (m - nh / a[i] + 1 >= 1) ++t[m - nh / a[i] + 1], nh += p;
  }
  int sum = 0;
  for (int i = m; i; --i) {
    sum += t[i] - k;
    if (sum > 0) return 0;
  }
  return 1;
}
int main() {
  scanf("%d %d %d %lld", &n, &m, &k, &p);
  long long l = 0, r = 1e15, mid;
  for (int i = 1; i <= n; ++i)
    scanf("%lld %lld", &h[i], &a[i]), l = max(l, a[i]);
  while (l < r) {
    mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%lld", l);
  return 0;
}
