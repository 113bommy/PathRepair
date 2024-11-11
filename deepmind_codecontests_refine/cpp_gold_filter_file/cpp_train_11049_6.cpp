#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long cho2(long long r) { return r * (r - 1); }
bool unlucky(long long x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return true;
    x /= 10;
  }
  return false;
}
vector<long long> pa((long long)3e5 + 5, -1);
long long leader(long long u) {
  if (pa[u] < 0)
    return u;
  else
    return pa[u] = leader(pa[u]);
}
void merge(long long u, long long v) {
  u = leader(u);
  v = leader(v);
  if (pa[u] < pa[v]) swap(u, v);
  pa[v] += pa[u];
  pa[u] = v;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n;
  cin >> n;
  long long m = n - 1;
  while (m--) {
    long long u, v, w;
    cin >> u >> v >> w;
    if (unlucky(w)) merge(u, v);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) ans += cho2(n + pa[leader(i)]);
  cout << ans << "\n";
  return 0;
}
