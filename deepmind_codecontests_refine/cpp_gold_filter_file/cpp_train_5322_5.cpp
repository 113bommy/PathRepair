#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
ll pwr(ll a, ll b);
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  int x;
  ld sum = 0, c = 0;
  for (int i = 1; i <= m; i++) {
    cin >> x, sum += x;
    if (i == h) c += x;
  }
  --sum, --n, --c;
  if (sum < n) return cout << -1, 0;
  if ((sum - c) < n) return cout << 1, 0;
  if (n == 0) return cout << 0, 0;
  ld ans = 1.0;
  while (n--) {
    ans *= ((sum - c) / sum);
    --sum;
  }
  ans = 1.0 - ans;
  cout << fixed << setprecision(8) << ans << "\n";
}
ll pwr(ll a, ll b) {
  a %= mod;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
