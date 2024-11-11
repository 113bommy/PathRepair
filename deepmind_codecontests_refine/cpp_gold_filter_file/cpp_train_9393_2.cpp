#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "-1\n";
    return;
  }
  if ((n - 1) % 6 != 0) {
    for (long long i = 1; i < n; i++) cout << "2";
    cout << "7\n";
  } else {
    for (long long i = 1; i < n - 1; i++) cout << "2";
    cout << "77\n";
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
