#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
static ll pow2cost(ll k) {
  if (k == 0LL) return 0LL;
  return (1LL << (k - 1)) * k;
}
int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  ll last = 0;
  for (ll k = 12; k >= 0; k--) {
    if (n >> k) {
      n -= 1LL << k;
      ans += pow2cost(k);
      ans += last;
      last = 1LL << k;
    }
  }
  cout << ans << endl;
  return 0;
}
