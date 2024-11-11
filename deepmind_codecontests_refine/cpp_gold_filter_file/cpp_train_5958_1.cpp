#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve() {
  ll n, g, b;
  cin >> n >> g >> b;
  ll req = (n + 1) / 2;
  if (n <= g) {
    cout << n << endl;
    return;
  }
  if (req <= g) {
    cout << n << endl;
    return;
  }
  ll x = req / g;
  ll ans = x * g + (x - 1) * b;
  if (req % g != 0) ans += (b + (req % g));
  std::cout << max(n, ans) << std::endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
