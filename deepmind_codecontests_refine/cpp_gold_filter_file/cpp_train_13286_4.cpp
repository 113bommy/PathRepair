#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lld = long double;
using vi = vector<int>;
using vll = vector<long long>;
ll factorial(ll n) {
  if (n == 0) {
    return 1;
  }
  return (n * factorial(n - 1));
}
ll choose(ll n, ll k) {
  ll res = 1;
  for (ll i = 0; i < k; i++) {
    res *= (n - i);
  }
  res /= factorial(k);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  k++;
  while (k--) {
    if (k == 0) {
      ans += choose(n, k);
    } else if (k == 1) {
      continue;
    } else if (k == 2) {
      ans += choose(n, k);
    } else if (k == 3) {
      ans += 2 * choose(n, k);
    } else if (k == 4) {
      ans += 9 * choose(n, k);
    }
  }
  cout << ans;
  return 0;
}
