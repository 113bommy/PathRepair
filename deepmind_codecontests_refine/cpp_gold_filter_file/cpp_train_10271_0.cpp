#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
int C[maxn];
struct frac {
  long long x, v;
  frac(long long xx = 0, long long vv = 0) : x(xx), v(vv) {}
  bool operator<(const frac &rhs) const { return x * rhs.v < rhs.x * v; }
  bool operator==(const frac &rhs) const { return x * rhs.v == rhs.x * v; }
} q[maxn];
pair<frac, frac> p[maxn];
int n, w;
long long x[maxn], v[maxn];
int lowbit(long long x) { return x & -x; }
int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}
void add(int x) {
  while (x <= n) {
    C[x]++;
    x += lowbit(x);
  }
}
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &x[i], &v[i]);
    if (x[i] < 0) {
      p[i] = make_pair(frac(-x[i], v[i] - w), frac(x[i], v[i] + w));
    } else
      p[i] = make_pair(frac(x[i], -v[i] + w), frac(-x[i], -v[i] - w));
    q[i] = p[i].second;
  }
  sort(q, q + n);
  sort(p, p + n);
  long long ans = 0;
  int m = unique(q, q + n) - q;
  for (int i = 0; i < n; i++) {
    int pt = lower_bound(q, q + m, p[i].second) - q + 1;
    ans += sum(pt);
    add(pt);
  }
  printf("%lld\n", ans);
}
