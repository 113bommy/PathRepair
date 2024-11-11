#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int stair = t1 * abs(x - y);
  int elevator = t2 * (abs(x - z) + abs(z - y)) + 3 * t3;
  if (elevator <= stair) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
