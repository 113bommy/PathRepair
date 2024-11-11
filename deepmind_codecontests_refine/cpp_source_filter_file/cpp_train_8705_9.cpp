#include <bits/stdc++.h>
using namespace std;
long long n, m, a[40], ans;
set<long long> s;
bool f;
void dfs(long long N, long long K) {
  if (N == 18) {
    if (f) {
      ans = max(ans, *--s.lower_bound(m - K));
    } else {
      ans = max(ans, K);
      s.insert(K);
    }
    return;
  }
  dfs(N + 1, (a[N] + K) % m);
  dfs(N + 1, K);
}
int32_t main() {
  s.insert(0);
  cin >> n >> m;
  for (long long l = 0; l < n; ++l) cin >> a[l];
  dfs(0, 0);
  for (long long l = 0; l < 18; ++l) a[l] = a[l + 18];
  f = 1;
  dfs(0, 0);
  cout << ans;
  return 0;
}
