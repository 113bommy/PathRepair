#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if ((n - 1) % 14 == 0 && (n - 1) > 0) {
      cout << "YES\n";
    } else if ((n - 2) % 14 == 0 && (n - 1) > 0) {
      cout << "YES\n";
    } else if ((n - 3) % 14 == 0 && (n - 1) > 0) {
      cout << "YES\n";
    } else if ((n - 4) % 14 == 0 && (n - 1) > 0) {
      cout << "YES\n";
    } else if ((n - 5) % 14 == 0 && (n - 1) > 0) {
      cout << "YES\n";
    } else if ((n - 6) % 14 == 0 && (n - 1) > 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
