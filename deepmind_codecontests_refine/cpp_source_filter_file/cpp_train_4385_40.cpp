#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (t2 * abs(x - z) + t2 * abs(x - y) + 2 * t3 <= t1 * abs(x - y))
    cout << "YES";
  else
    cout << "NO";
}
