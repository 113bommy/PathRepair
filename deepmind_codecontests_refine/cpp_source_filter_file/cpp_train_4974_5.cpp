#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll D;
  cin >> D;
  vector<ll> C(26);
  for (ll i = 0; i < 26; i++) cin >> C[i];
  vector<vector<ll>> S(365, vector<ll>(26, 0));
  for (ll i = 0; i < 365; i++) {
    for (ll j = 0; j < 26; j++) {
      cin >> S[i][j];
    }
  }
  for (ll i = 0; i < 365; i++) {
    ll ans = rand() / 26 + 1;
    cout << ans << '\n';
  }
  return 0;
}
