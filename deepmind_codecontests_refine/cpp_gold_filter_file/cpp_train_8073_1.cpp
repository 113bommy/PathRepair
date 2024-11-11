#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 100005;
pair<long long, int> f0[N], f[N];
pair<long long, int> bsd(pair<long long, int> a, pair<long long, int> b) {
  if (a.first > b.first || a.first == b.first && a.second < b.second)
    return a;
  else
    return b;
}
long long l[N], r[N];
int query(long long x, int n) { return lower_bound(r + 1, r + n + 1, x) - r; }
int main() {
  int i, j, n;
  long long L, p, t;
  scanf("%I64d%d%I64d%I64d", &L, &n, &p, &t);
  for (i = 1; i <= n; i++) scanf("%I64d%I64d", &l[i], &r[i]);
  l[n + 1] = L + 1, r[n + 1] = L + 2;
  for (i = 1; i <= n; i++) {
    f0[i] = bsd(f0[i], f0[i - 1]);
    f[i] = bsd(f[i], make_pair(f0[i].first + (r[i] - l[i]) / p,
                               l[i] + ((r[i] - l[i]) / p) * p));
    long long t0 = f[i].second + t;
    j = query(t0, n + 1);
    if (j > n) continue;
    if (l[j] >= t0) {
      f0[j] = bsd(f0[j], make_pair(f[i].first, t0));
      continue;
    }
    f[j] = bsd(f[j], make_pair(f[i].first + (r[j] - t0) / p,
                               t0 + ((r[j] - t0) / p) * p));
    f0[j + 1] = bsd(f0[j + 1], make_pair(f[i].first, t0));
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) ans = max(ans, f[i].first);
  printf("%I64d\n", ans);
  return 0;
}
