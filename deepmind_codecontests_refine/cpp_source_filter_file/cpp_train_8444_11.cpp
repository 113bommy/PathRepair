#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, b, r;
  cin >> y >> b >> r;
  int m = min(b, min(y, r));
  cout << 3 * m;
  return 0;
}
