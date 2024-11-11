#include <bits/stdc++.h>
using namespace std;
long long n, m, m1, len, ans, nex[1000000], wen[1000000], hea[1000000],
    l[1000000], r[1000000], a[1000000], fa[1000000];
vector<long long> v;
struct arr {
  long long x, y, z, p;
} b[1000000];
long long find(long long x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void add(long long x, long long y) {
  ++len;
  nex[len] = hea[x];
  wen[len] = y;
  hea[x] = len;
}
void dfs(long long x, long long y) {
  long long bo = 1;
  l[x] = 100000000;
  for (long long i = hea[x]; i; i = nex[i])
    if (wen[i] != y) {
      dfs(wen[i], x);
      bo = 0;
      l[x] = min(l[x], l[wen[i]]);
      r[x] = max(r[x], r[wen[i]]);
    }
  if (bo) l[x] = r[x] = m++;
  b[++m1] = {l[x], r[x] + 1, a[x], x};
}
bool cmp(arr x, arr y) { return x.z < y.z; }
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i < n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    add(x, y);
    add(y, x);
  }
  m = 1;
  dfs(1, 0);
  sort(b + 1, b + n + 1, cmp);
  for (long long i = 1; i <= m; i++) fa[i] = i;
  for (long long i = 1, j; i <= n; i = j + 1) {
    j = i;
    while (b[j + 1].z == b[j].z && j < m) ++j;
    for (long long k = i; k <= j; k++)
      if (find(b[k].x) != find(b[k].y)) v.push_back(b[k].p);
    for (long long k = i; k <= j; k++)
      if (find(b[k].x) != find(b[k].y)) {
        ans += b[k].z;
        fa[find(b[k].x)] = find(b[k].y);
      }
  }
  sort(v.begin(), v.end());
  printf("%lld %lld\n", ans, v.size());
  for (long long i = 0; i < v.size(); i++) printf("%lld ", v[i]);
  return 0;
}
