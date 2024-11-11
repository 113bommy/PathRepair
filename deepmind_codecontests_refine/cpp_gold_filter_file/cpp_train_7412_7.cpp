#include <bits/stdc++.h>
using namespace std;
string uni = "abcdefghijklmnopqrstuvwxyz";
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && ((2 * a >= b) && (2 * b) >= a)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
