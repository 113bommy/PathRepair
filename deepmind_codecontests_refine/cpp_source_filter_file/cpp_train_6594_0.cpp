#include <bits/stdc++.h>
using namespace std;
long long n, u, r;
long long a[35], b[35], k[35], p[35], ans = 0;
void dfs(long long x, long long lst) {
  if ((u - x + 10) & 1) {
    long long sum = 0;
    for (long long i = 1; i <= n; i++) sum += k[i] * a[i];
    ans = max(ans, sum);
    if (x == u + 1) return;
  }
  long long t[35];
  for (long long i = 1; i <= n; i++) t[i] = a[i];
  if (lst != 1) {
    for (long long i = 1; i <= n; i++) a[i] = t[i] ^ b[i];
    dfs(x + 1, 1);
  }
  for (long long i = 1; i <= n; i++) a[i] = t[p[i]] + r;
  dfs(x + 1, 2);
  for (long long i = 1; i <= n; i++) a[i] = t[i];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> u >> r;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) cin >> b[i];
  for (long long i = 1; i <= n; i++) cin >> k[i];
  for (long long i = 1; i <= n; i++) cin >> p[i];
  dfs(1, 2);
  cout << ans;
  return 0;
}
