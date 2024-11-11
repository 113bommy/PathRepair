#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3, st, el;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  st = abs(x - y) * t1;
  el = abs(z - x) * t2 + abs(x - y) * t2 + 3 * t3;
  if (el <= st)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
