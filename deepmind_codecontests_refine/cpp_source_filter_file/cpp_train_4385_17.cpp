#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (abs(x - y) * t2 + t3 * 2 + t2 * abs(z - x) < abs(x - y) * t1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
