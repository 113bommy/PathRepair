#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll MOD = (ll)1e9 + 7;
ll exp(ll b) {
  if (b == 1) {
    return 2LL;
  }
  ll res = exp(b / 2);
  res %= MOD;
  res *= res;
  res %= MOD;
  if (b % 2 == 1) {
    res *= 2;
  }
  res %= MOD;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll k;
  cin >> k;
  if (k == 1) {
    cout << 6 << '\n';
    return 0;
  }
  ll node_count = (1LL << k) - 1;
  ll p = node_count - 1;
  ll ans = 6LL * exp(2LL * p);
  ans %= MOD;
  cout << ans << '\n';
  return 0;
}
