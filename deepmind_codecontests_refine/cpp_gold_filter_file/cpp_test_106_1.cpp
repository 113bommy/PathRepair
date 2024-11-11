#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long;
void solve() {
  ll n;
  cin >> n;
  for (ll i = 2; i <= n + 1; i++) {
    cout << i << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
