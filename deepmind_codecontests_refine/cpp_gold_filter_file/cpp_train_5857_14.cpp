#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, r;
  cin >> n >> r;
  if (n > r) {
    cout << 1LL * r * (r + 1) / 2 << '\n';
  } else {
    cout << 1LL * n * (n - 1) / 2 + 1 << '\n';
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
