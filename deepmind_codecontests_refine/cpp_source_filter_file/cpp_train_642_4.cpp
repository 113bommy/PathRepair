#include <bits/stdc++.h>
using namespace std;
const long long N = 5010, inf = 1e9 + 7;
long long t, n, f[N][N];
struct node {
  long long m, p;
  bool friend operator<(node x, node y) { return x.m < y.m; }
} a[N];
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld %lld", &a[i].m, &a[i].p);
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= n; i++)
      for (long long j = 0; j <= n; j++) f[i][j] = inf;
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j <= n; j++) {
        f[i + 1][j - 1] = min(f[i + 1][j - 1], f[i][j] + a[i + 1].p);
        if (i + j >= a[i + 1].m) f[i + 1][j] = min(f[i + 1][j], f[i][j]);
      }
    printf("%lld\n", f[n][0]);
  }
  return 0;
}
