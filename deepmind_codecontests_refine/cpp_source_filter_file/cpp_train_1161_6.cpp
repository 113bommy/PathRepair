#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 2e18;
constexpr long long MOD = 1e9 + 7;
constexpr long long MAXN = 2e5 + 3;
void solve() {
  long long n;
  cin >> n;
  vector<long long> d(n + 1);
  vector<long long> fat(n + 1);
  fat[0] = 1;
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    cin >> u >> v;
    ++d[u], ++d[v];
  }
  for (long long i = 1; i <= n; ++i) fat[i] = (i * fat[i - 1]) % MOD;
  long long ans = n;
  for (long long i = 1; i <= n; ++i) {
    ans = (ans * fat[d[i]]) % MOD;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) solve();
}
