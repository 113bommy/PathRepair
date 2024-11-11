#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int z, x, i, n, t, a, b, f = 0;
  cin >> t;
  cin >> x;
  z = 7 - x;
  while (t--) {
    cin >> a >> b;
    if (a == x || a == z || b == x || b == z) {
      cout << "No" << endl;
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << "Yes" << endl;
  }
  return 0;
}
