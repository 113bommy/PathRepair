#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> sides(n);
    for (int i = 0; i < (n); ++i) cin >> sides[i];
    if (sides[1] > (sides[n - 1] - sides[0]))
      cout << -1 << "\n";
    else
      cout << "1 2 " << n << "\n";
  }
  return 0;
}
