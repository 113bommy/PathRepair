#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int counter = 0;
vector<pair<int, int>> vec;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int stairs = abs(x - y) * t1;
  int elevator = abs((x - z) * t2) + 2 + abs((x - y) * t2) + 1;
  if (elevator <= stairs) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
