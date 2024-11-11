#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll q;
  cin >> q;
  for (ll _ = 0; _ < q; _++) {
    ll n, k;
    cin >> n >> k;
    ll grundy;
    if (k % 3 == 0) {
      if (n % (k + 1) == k) {
        grundy = 3;
      } else {
        n %= k + 1;
        grundy = n % 3;
      }
    } else {
      grundy = n % 3;
    }
    cout << (grundy != 0 ? "Alice" : "Bob") << endl;
  }
}
