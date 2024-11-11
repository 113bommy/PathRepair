#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  bool hepi = true;
  if (x > a || y > a + b - x || z > a + b + c - x + y) hepi = false;
  if (hepi)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
