#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, m;
  cin >> n >> d;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (y >= -x + d && y <= x + d && y >= x - d && y <= -x + n + n - d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
