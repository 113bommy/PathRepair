#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  int m;
  cin >> m;
  int x, y;
  while (m--) {
    cin >> x >> y;
    if (y >= x - d && y <= x + d && y >= x - d && y <= 2 * n - d - x)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
