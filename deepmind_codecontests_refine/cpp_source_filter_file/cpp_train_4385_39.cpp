#include <bits/stdc++.h>
using namespace std;
int x, y, z, t1, t2, t3;
int abs(int x) { return x < 0 ? -x : x; }
int main() {
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (abs(z - x) * t2 + 1 + 1 + abs(x - y) * t2 + 1 <= abs(x - y) * t1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
