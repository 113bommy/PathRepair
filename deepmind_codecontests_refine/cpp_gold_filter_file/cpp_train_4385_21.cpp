#include <bits/stdc++.h>
using namespace std;
int can[10];
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (t1 * abs(x - y) >= (abs(x - z) + abs(x - y)) * t2 + 3 * t3)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
