#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int tt = 2e5 + 10, mod = 1e9 + 7, INF = 0x7f7f7f7f7f7f7f7f;
ll n, k, m, t;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<ll> G(n);
    for (int i = 0; i < n; i++) cin >> G[i];
    sort(G.begin(), G.end());
    vector<ll> f(n + 1);
    for (int i = 0; i < n; i++) {
      f[i + 1] = f[i] + G[i];
    }
    ll ans = (ll)9e18;
    for (int i = 0; i < n; i++) {
      ll sum = f[n - i] + G[0] * i;
      ll cur = i;
      if (sum > k) {
        ll dif = sum - k;
        cur += (dif + i) / (i + 1);
      }
      ans = min(ans, cur);
    }
    cout << ans << endl;
  }
}
