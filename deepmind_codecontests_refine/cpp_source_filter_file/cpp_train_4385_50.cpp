#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int ele = t2 * (abs(z - x) + abs(x - y)) + t3;
  int st = t1 * abs(x - y);
  if (st < ele)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
