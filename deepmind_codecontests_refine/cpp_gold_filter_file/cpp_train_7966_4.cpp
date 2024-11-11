#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, MAXN = 1e6 + 10, INF = 1e18;
long long ans = 1, n, m, pw = 1, mn;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    ans *= (2 * m - 1);
    ans += pw;
    pw *= m;
    pw %= MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
