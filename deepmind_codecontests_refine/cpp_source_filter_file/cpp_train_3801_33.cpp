#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll x;
  cin >> x;
  int k = 0;
  for (ll n = 1; n <= (int)1e6; ++n) {
    ll a = 6 * x + n * (n - 1) * (n + 1), b = 3 * n * (n + 1);
    if (a % b == 0 && a / b >= n) {
      ++k;
    }
  }
  for (ll n = (int)1e6; n >= 1; --n) {
    ll a = 6 * x + n * (n - 1) * (n + 1), b = 3 * n * (n + 1);
    if (a % b == 0 && a / b > n) {
      ++k;
    }
  }
  cout << k << endl;
  for (ll n = 1; n <= (int)1e6; ++n) {
    ll a = 6 * x + n * (n - 1) * (n + 1), b = 3 * n * (n + 1);
    if (a % b == 0 && a / b >= n) {
      cout << n << ' ' << a / b << endl;
    }
  }
  for (ll n = (int)1e6; n >= 1; --n) {
    ll a = 6 * x + n * (n - 1) * (n + 1), b = 3 * n * (n + 1);
    if (a % b == 0 && a / b > n) {
      cout << a / b << ' ' << n << endl;
    }
  }
}
