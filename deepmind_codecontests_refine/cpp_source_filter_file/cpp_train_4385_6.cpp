#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int diff = abs(y - x);
  int ans = diff * t1;
  if (ans >= ((z - x) * t2) + (t3 * 2) + (diff * t2)) {
    std::cout << "YES" << endl;
  } else {
    std::cout << "NO" << endl;
  }
}
