#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (abs(z - x) * t2 + abs(x - y) * t2 + 2 * t3 <= abs(x - y) * t1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
