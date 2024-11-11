#include <bits/stdc++.h>
using namespace std;
void solve() {
  long double n;
  cin >> n;
  if (n == 1) {
    cout << 0 << "\n";
    return;
  }
  long double root = sqrt(n);
  cout << ceil(root + root - 2) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
