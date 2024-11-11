#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = (int)2e5 + 5;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 5;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(15);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a >= c) {
      cout << -1 << " ";
    } else
      cout << 1 << " ";
    if (a * b > c) {
      cout << b << "\n";
    } else
      cout << -1 << "\n";
  }
  return 0;
}
