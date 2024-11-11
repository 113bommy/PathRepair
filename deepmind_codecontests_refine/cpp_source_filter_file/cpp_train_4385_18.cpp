#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (abs(x - y) * t1 >= abs(x - z) * t2 + t3 + abs(x - y) * t2 + t3)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
