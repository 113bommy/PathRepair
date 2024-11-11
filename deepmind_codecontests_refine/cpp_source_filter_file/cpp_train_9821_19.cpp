#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, i, n;
  cin >> x >> y >> n;
  for (i = 2; i <= n; i++) {
    z = x + y;
    x = y;
    y = z;
  }
  cout << x << endl;
  return 0;
}
