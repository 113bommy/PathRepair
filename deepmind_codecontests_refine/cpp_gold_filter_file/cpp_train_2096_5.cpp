#include <bits/stdc++.h>
using namespace std;
const long long MAX = (long long)2e5 + 100;
long long mod = (long long)1e9 + 7, mod2 = (long long)1e9 + 9;
long long n, k;
void solve() {
  long long ang;
  cin >> ang;
  for (int n = 3; n <= 1000; n++) {
    long long ok = 0;
    for (int k = 1; k <= n - 2; k++) {
      if (180 * k == n * ang) ok = 1;
    }
    if (ok) {
      cout << n << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  long long q;
  cin >> q;
  while (q--) solve();
}
