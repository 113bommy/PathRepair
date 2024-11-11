#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, q, a[100005], height[100005], b[100005], tot, ans, now, B[100005],
    H[100005];
struct Union_Find_Set {
  long long fa[100005], siz[100005];
  void init(long long x) {
    for (long long i = 1; i <= x; i++) fa[i] = i, siz[i] = 1;
  }
  long long find(long long x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void merge(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    fa[x] = y;
    ans += B[now] * (siz[x] * siz[y]);
    siz[y] += siz[x];
  }
} S;
vector<long long> G[100005];
signed main() {
  n = read();
  q = read();
  long long X = 0;
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    if (i > 1) height[i] = abs(a[i] - a[i - 1]), B[++X] = height[i];
  }
  sort(B + 1, B + X + 1);
  tot = unique(B + 1, B + 1 + X) - B - 1;
  for (long long i = 2; i <= n; i++)
    height[i] = lower_bound(B + 1, B + 1 + tot, height[i]) - B;
  while (q--) {
    ans = 0;
    S.init(n);
    long long l = read(), r = read();
    for (long long i = l + 1; i <= r; i++) G[height[i]].push_back(i);
    for (long long i = 1; i <= n; i++) {
      now = i;
      long long siz = G[i].size();
      for (long long j = 0; j < siz; j++) S.merge(G[i][j] - 1, G[i][j]);
      G[i].clear();
    }
    printf("%lld\n", ans);
  }
}
