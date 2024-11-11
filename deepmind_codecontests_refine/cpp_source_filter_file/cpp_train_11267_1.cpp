#include <bits/stdc++.h>
using namespace std;
struct node {
  long long val1, val2[10];
} a[100005];
long long n, p, k, f[100005][305];
bool cmp(node a, node b) { return a.val1 > b.val1; }
signed main() {
  cin >> n >> p >> k;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i].val1);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= p; j++) scanf("%lld", &a[i].val2[j]);
  sort(a + 1, a + 1 + n, cmp);
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j < (1 << p); j++) f[i][j] = -1000000000;
  f[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < (1 << p); j++) {
      long long cnt = 0;
      for (long long k = 1; k <= p; k++) {
        if ((j & (1 << (k - 1))) == 0) continue;
        f[i][j] = max(f[i][j], f[i - 1][j ^ (1 << (k - 1))] + a[i].val2[k]);
        cnt++;
      }
      if (i - cnt <= k)
        f[i][j] = max(f[i][j], f[i - 1][j] + a[i].val1);
      else
        f[i][j] = max(f[i][j], f[i - 1][j]);
    }
  }
  cout << f[n][(1 << p) - 1] << endl;
  return 0;
}
