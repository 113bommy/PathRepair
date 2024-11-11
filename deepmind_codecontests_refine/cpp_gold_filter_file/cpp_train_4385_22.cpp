#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, z, t1, t2, t3;
  while (cin >> x >> y >> z >> t1 >> t2 >> t3) {
    long long int stairTime = t1 * abs(x - y);
    long long int elavetorLocationTime = abs(x - z) * t2;
    long long int elevatorTime =
        t2 * abs(x - y) + (t3 * 2) + elavetorLocationTime + t3;
    if (stairTime >= elevatorTime) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
