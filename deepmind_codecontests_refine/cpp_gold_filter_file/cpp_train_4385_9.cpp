#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int stairs = abs(x - y) * t1;
  int elevator = abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3;
  if (elevator <= stairs) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
