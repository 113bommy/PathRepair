#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll P = 1000000007, N;
  cin >> N;
  ll u = 1, n8 = 1, n9 = 1;
  for (ll i = 0; i < N; i++) {
    u = (u * 10) % P;
    n8 = (n8 * 8) % P;
    n9 = (n9 * 9) % P;
  }
  ll ans = (u + n8 - 2 * n9 + P) % P;
  cout << ans;
}
