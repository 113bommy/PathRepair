#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int s, i, e, ans;
void solve(void) {
  cin >> s >> i >> e;
  if ((s + e) <= i) {
    cout << "0\n";
    return;
  }
  double deli = ((s + e - i) / 2.00) - 1.00;
  deli = ceil(deli);
  int ans = deli;
  cout << min(ans, e) + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
