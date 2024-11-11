#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  int y;
  int z;
  int t1;
  int t2;
  int t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int ediff = (z >= x) ? z - x : x - z;
  int fdiff = (y >= x) ? y - x : x - y;
  int elevatorTime = 2 * t3 + (ediff + fdiff) * t2;
  int stairsTime = fdiff * t1;
  if (elevatorTime <= stairsTime)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
