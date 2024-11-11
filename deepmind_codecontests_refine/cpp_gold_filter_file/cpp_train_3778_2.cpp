#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long p, q;
  cin >> p >> q;
  if (p % q) {
    cout << p << '\n';
    return;
  }
  vector<long long> a{q};
  for (long long i = 2; i * i <= q; i++) {
    if (q % i == 0) {
      a.push_back(i);
      a.push_back(q / i);
    }
  }
  long long ans = 1;
  for (auto i : a) {
    long long temp = p;
    while (temp % i == 0) {
      temp /= i;
      if (temp % q) {
        ans = max(ans, temp);
        break;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
