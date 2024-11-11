#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double x, y, k;
    ll z;
    cin >> x >> y >> k;
    z = ((k * y + k - 1 + x - 2) / (x - 1)) + k;
    cout << z;
  }
  return 0;
}
