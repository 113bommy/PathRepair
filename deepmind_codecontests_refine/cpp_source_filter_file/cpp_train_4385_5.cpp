#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (abs(y - x) * t1 >= t3 * 2 + (abs(z - x) + abs(x - y)) * t2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
