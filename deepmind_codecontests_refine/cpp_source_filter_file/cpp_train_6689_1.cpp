#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn];
bool dfs1(long long s, long long e) {
  if (e & 1) {
    if (s & 1) return 0;
    return 1;
  }
  if (s > e / 2) return (s & 1);
  if (s > e / 4) return 1;
  return dfs1(s, e / 4);
}
bool dfs2(long long s, long long e) {
  if (2ll * s > e) return 1;
  return (!dfs2(s, e / 2));
}
int main() {
  scanf("%d", &n);
  a[0] = 0;
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    if (dfs1(x, y))
      a[i] = b[i - 1];
    else
      a[i] = a[i - 1];
    if (dfs2(x, y))
      b[i] = b[i - 1];
    else
      b[i] = a[i - 1];
  }
  printf("%d %d\n", a[n], b[n]);
  return 0;
}
