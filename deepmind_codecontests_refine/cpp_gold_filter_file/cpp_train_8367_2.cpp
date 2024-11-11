#include <bits/stdc++.h>
using namespace std;
long long n;
const long long N = 2e5 + 100;
long long l[N], r[N];
struct node {
  long long x, y, id;
} a[N];
bool cmp1(node c, node d) { return c.x < d.x; }
bool cmp2(node c, node d) { return c.y > d.y; }
struct BIT {
  long long sum[N];
  void cl() { memset(sum, 0, sizeof(sum)); }
  void add(long long x, long long y) {
    while (x <= 2 * n) sum[x] += y, x += x & (-x);
  }
  long long gsum(long long x) {
    long long s = 0;
    while (x) s += sum[x], x -= x & (-x);
    return s;
  }
  long long gsum(long long x, long long y) { return gsum(y) - gsum(x - 1); }
} bit;
long long calc(long long x) { return x * (x - 1) * (x - 2) / 6; }
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    a[i].x = u, a[i].y = v, a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp1);
  for (long long i = 1; i <= n; i++) {
    long long u = a[i].x, v = a[i].y;
    r[a[i].id] += bit.gsum(u - 1);
    bit.add(v, 1);
  }
  bit.cl();
  for (long long i = 1; i <= n; i++) {
    long long u = a[i].x, v = a[i].y;
    r[a[i].id] += bit.gsum(v + 1, 2 * n);
    bit.add(v, 1);
  }
  bit.cl();
  for (long long i = n; i >= 1; i--) {
    long long u = a[i].x, v = a[i].y;
    l[a[i].id] += bit.gsum(v - 1);
    bit.add(v, 1);
  }
  sort(a + 1, a + 1 + n, cmp2);
  bit.cl();
  for (long long i = 1; i <= n; i++) {
    long long u = a[i].x, v = a[i].y;
    r[a[i].id] += bit.gsum(v + 1, 2 * n);
    bit.add(u, 1);
  }
  long long s1 = 0, s2 = 0;
  for (long long i = 1; i <= n; i++) {
    s1 += l[i] * r[i];
    s2 += (n - l[i] - r[i] - 1) * (l[i] + r[i]);
  }
  cout << calc(n) - s1 - s2 / 2 << endl;
  return 0;
}
