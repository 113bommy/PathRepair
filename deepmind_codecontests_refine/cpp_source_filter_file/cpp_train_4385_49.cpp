#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int stair = abs(y - x) * t1;
  int elevator = t2 * (abs(z - x) + abs(y - x)) + 2 * t3;
  if (stair < elevator)
    cout << "NO";
  else
    cout << "YES";
}
