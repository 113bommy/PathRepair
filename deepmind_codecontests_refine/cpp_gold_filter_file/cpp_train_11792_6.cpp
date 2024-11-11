#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18 + 47;
const int INF = 1e9 + 47;
const int MOD = 998244353;
const int modulo = 1e8;
const int nax = 2 * (int)1e5 + 10;
const double EPS = 1e-9;
const double PI = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int tt;
  cin >> tt;
  for (int test = (1); test < (tt + 1); test++) {
    long long n, k;
    cin >> n >> k;
    long long l1, r1;
    cin >> l1 >> r1;
    long long l2, r2;
    cin >> l2 >> r2;
    if (l1 > l2) swap(l2, l1);
    if (r1 > r2) swap(r1, r2);
    long long ans = LINF;
    if (l2 <= r1) {
      long long cur = (r1 - l2) * n;
      if (cur >= k) {
        cout << 0 << '\n';
        continue;
      }
      long long have = ((l2 - l1) + (r2 - r1)) * n;
      if (have + cur >= k) {
        cout << k - cur << '\n';
      } else {
        cur += have;
        ans = ((l2 - l1) + (r2 - r1)) * n;
        k -= cur;
        cout << ans + k * 2 << '\n';
      }
      continue;
    }
    long long invest = l2 - r1;
    for (int i = (0); i < (n); i++) {
      long long price = invest * (i + 1);
      long long have = (r2 - l1) * (i + 1);
      if (have >= k) {
        ans = min(ans, price + k);
      } else {
        ans = min(ans, have + (k - have) * 2 + price);
      }
    }
    cout << ans << '\n';
  }
}
