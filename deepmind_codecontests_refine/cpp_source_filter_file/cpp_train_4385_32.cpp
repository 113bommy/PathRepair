#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int ans;
  ans = abs(x - z) * t2 + 3 * t3 + abs(x - y) * t2;
  if (ans > ((x - y) * t1)) {
    cout << "no";
  } else
    cout << "yes";
}
