#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 6e1 + 1;
ll t, n, m;
ll mp[N];
void upd(ll val) {
  ll i = 0;
  while ((1ll << i) != val) i++;
  mp[i]++;
}
ll get(ll val) {
  ll ans = 0;
  for (ll i = 0; (1ll << i) <= val; i++) {
    if (val & (1ll << i)) {
      if (!mp[i]) {
        ll j = i + 1;
        while (j < N && !mp[j]) j++;
        ans += j - i;
        if (j == N) return -1;
        mp[j]--;
        mp[i] = 2;
        for (ll k = i + 1; k < j; k++) mp[k]++;
      }
      mp[i]--;
    }
    mp[i + 1] += mp[i] / 2;
  }
  return ans;
}
void Solve() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    fill(mp, mp + N, 0);
    for (int i = 0, v; i < m; i++) cin >> v, upd(v);
    cout << get(n) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
