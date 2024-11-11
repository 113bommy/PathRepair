#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Node {
  int s, a, b;
  void input() { scanf("%d%d%d", &s, &a, &b); }
  bool operator<(const Node &t) const { return a - b > t.a - t.b; }
} q[N];
long long ans, tot;
int n, s;
long long cal(long long x) {
  long long tmp = 1ll * x * s, ret = 0;
  for (int i = 1; i <= n && q[i].a - q[i].b > 0; i++) {
    ret += min(tmp, 1ll * q[i].s) * (q[i].a - q[i].b);
    tmp -= min(tmp, 1ll * q[i].s);
  }
  tmp = 1ll * (tot - x) * s;
  for (int i = n; i > 0 && q[i].b - q[i].a > 0; i--) {
    ret += min(tmp, 1ll * q[i].s) * (q[i].b - q[i].a);
    tmp -= min(tmp, 1ll * q[i].s);
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) q[i].input(), tot += q[i].s;
  sort(q + 1, q + n + 1);
  tot = (tot + s - 1) / s;
  for (int i = 1; i <= n; i++) ans += 1ll * q[i].s * min(q[i].a, q[i].b);
  long long l = 0, r = tot;
  while (l + 2 < r) {
    long long foot = (r - l) / 3;
    long long t1 = l + foot, t2 = l + 2 * foot;
    if (cal(t1) >= cal(t2))
      r = t2;
    else
      l = t1;
  }
  long long mx = 0;
  for (long long i = l; i <= r; i++) mx = max(mx, cal(i));
  printf("%I64d\n", ans + mx);
  return 0;
}
