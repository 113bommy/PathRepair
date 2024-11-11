#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, b, r;
  cin >> y >> b >> r;
  int m = min(b, min(y + 1, r - 1));
  cout << 3 * m;
  return 0;
}
