#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0)->sync_with_stdio(false);
  ll t;
  cin >> t;
  while (t--) {
    ll N;
    cin >> N;
    ll k = ceil(sqrtl((long double)N));
    N -= (k - 1) * (k - 1);
    if (N <= k) {
      cout << N << ' ' << k << '\n';
    } else {
      N -= k;
      cout << k << ' ' << k - N << '\n';
    }
  }
}
