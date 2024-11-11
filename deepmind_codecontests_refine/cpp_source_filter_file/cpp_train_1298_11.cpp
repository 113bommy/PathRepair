#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p;
const long long maxn = 1e5 + 5;
long long a[maxn], h[maxn];
long long he[maxn];
struct bamboo {
  long long ne;
  long long id;
  bool operator<(const bamboo& x) const { return x.ne > ne; }
} bam[maxn];
bool check(long long x) {
  priority_queue<bamboo> q;
  for (long long i = 1; i <= n; i++) he[i] = x;
  for (long long i = 1; i <= n; i++)
    if (he[i] - a[i] * m < h[i]) q.push({x / a[i], i});
  for (long long i = 1; i <= m; i++)
    for (long long j = 1; j <= k; j++) {
      if (!q.size()) return 1;
      bamboo y = q.top();
      q.pop();
      if (y.ne < i) return 0;
      he[y.id] += p;
      if (he[y.id] - a[y.id] * m < h[y.id]) q.push({he[y.id] / a[y.id], y.id});
    }
  return q.empty();
}
signed main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  for (long long i = 1; i <= n; i++) scanf("%d%d", &h[i], &a[i]);
  long long l = 0, r = 0;
  for (long long i = 1; i <= n; i++) r = max(r, (h[i] + a[i] * m));
  while (l < r) {
    long long mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
