#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int d = 0;
  cin >> n >> d;
  int m = 0;
  cin >> m;
  int x = 0;
  int y = 0;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if ((y <= x + d) && (y <= -x + 2 * n - d) && (y >= x - d) && (y >= -x + d))
      cout << "YES" << endl;
    else
      cout << "NO";
  }
  return 0;
}
