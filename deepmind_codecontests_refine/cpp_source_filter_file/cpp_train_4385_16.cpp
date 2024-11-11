#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (x == y) {
    cout << "YES" << endl;
    return 0;
  }
  int st = (abs(x - y)) * t1;
  int el = (abs(x - z)) * t2 + (abs(x - y)) * t2 + 3;
  if (st < el)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
