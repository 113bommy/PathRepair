#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  cout << 2 << " " << 3 << "\n";
  cout << ((1ll << 18) | k) << " " << k << " " << 0 << "\n";
  cout << (1ll << 18) << " " << (k | (1ll << 18)) << " " << k << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  q = 1;
  while (q--) solve();
}
