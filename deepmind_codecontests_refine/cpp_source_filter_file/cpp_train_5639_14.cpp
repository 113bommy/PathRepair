#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, ma = 0, z, in;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    z += b;
    z -= a;
    if (z > ma) ma = z;
  }
  cout << ma << endl;
  return 0;
}
