#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> fact(n + 5);
  fact[1] = 1;
  for (int i = 2; i < n + 2; ++i) {
    fact[i] = i * fact[i - 1];
  }
  int x = n / 2 - 1;
  ll ans = fact[2 * x + 1] / (x + 1);
  cout << ans << '\n';
  return 0;
}
