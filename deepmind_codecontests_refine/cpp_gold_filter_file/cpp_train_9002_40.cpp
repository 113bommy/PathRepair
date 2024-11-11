#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    m += (xx - x + 1) * (yy - y + 1);
  }
  cout << m;
  return 0;
}
