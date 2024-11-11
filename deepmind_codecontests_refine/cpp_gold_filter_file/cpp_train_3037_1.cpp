#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (auto &i : v) cin >> i;
  vector<ll> pre(n + 1);
  pre[0] = 0;
  for (ll i = 1; i <= n; i++) pre[i] = pre[i - 1] + v[i - 1];
  ll q;
  cin >> q;
  ll a, b;
  while (q--) {
    cin >> a >> b;
    cout << ll((pre[b] - pre[a - 1]) / 10) << "\n";
  }
  return 0;
}
