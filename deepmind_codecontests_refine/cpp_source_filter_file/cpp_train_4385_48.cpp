#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int res1 = ((abs(z - x) + abs(y - x)) * t2) + 2 * t3;
  int res2 = t1 * (abs(y - x));
  if (res1 <= res2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
