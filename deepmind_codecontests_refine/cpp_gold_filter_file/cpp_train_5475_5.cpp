#include <bits/stdc++.h>
using namespace std;
const long long N = 5010;
long long x[N], f[N][N], q[N * 10], s[N];
long long sum[N];
struct P {
  long long p, c;
} h[N];
bool cmp(P a, P b) { return a.p < b.p; }
signed main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &x[i]);
  for (long long i = 1; i <= m; i++) scanf("%lld%lld", &h[i].p, &h[i].c);
  sort(x + 1, x + n + 1);
  sort(h + 1, h + m + 1, cmp);
  for (long long i = 1; i <= m; i++) sum[i] = sum[i - 1] + h[i].c;
  if (sum[m] < n) return printf("-1"), 0;
  memset(f, 0x3f, sizeof(f));
  long long l, r;
  f[0][0] = 0;
  for (long long i = 1; i <= m; i++) {
    l = 0, r = 0, q[++r] = 0, f[i][0] = 0;
    for (long long j = 1; j <= sum[i] && j <= n; j++) {
      f[i][j] = f[i - 1][j];
      s[j] = s[j - 1] + abs(x[j] - h[i].p);
      while (j - q[l] > h[i].c ||
             l <= r && f[i - 1][q[l]] - s[q[l]] > f[i - 1][j] - s[j])
        l++;
      q[++r] = j, f[i][j] = min(f[i][j], s[j] + f[i - 1][q[l]] - s[q[l]]);
    }
  }
  printf("%lld", f[m][n]);
  return 0;
}
