#include <bits/stdc++.h>
using vi = std::vector<long long int>;
using vvi = std::vector<vi>;
using pii = std::pair<long long int, long long int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using namespace std;
const long long int N = 2e6 + 10;
const long long int inf = 1e18 + 10;
const long double Pi = 3.14159265;
long long int n, k, z, a[N], p[N], ans, ma, pair_sum;
void solve() {
  cin >> n >> k >> z;
  ans = 0;
  ma = 0;
  pair_sum = 0;
  for (long long int i = 1; i <= n; i++) cin >> a[i], p[i] = a[i] + p[i - 1];
  for (long long int i = 1; i <= k + 1; i++) {
    pair_sum = max(pair_sum, p[i + 1] - p[i - 1]);
    for (long long int x = 0; x <= k; x++) {
      if (x + x - 1 <= k - i) ans = max(ans, (pair_sum * (x)) + p[i]);
    }
  }
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  long long int xx = 0;
  long long int t;
  cin >> t;
  while (t--) {
    ;
    solve();
    cout << "\n";
  }
  return 0;
}
