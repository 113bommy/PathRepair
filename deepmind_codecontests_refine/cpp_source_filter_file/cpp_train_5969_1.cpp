#include <bits/stdc++.h>
using namespace std;
int main() {
  int z;
  cin >> z;
  while (z--) {
    long long n, m, x, y, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x = abs(x1 - x2) + 1;
    y = abs(y1 - y2) + 1;
    long long fin = (n * m) - 2 * (n - x + 1) * (m - y + 1);
    if ((n - 2 * x + 2) > 0 && (m - 2 * y + 2) > 0) {
      fin += (n - 2 * x + 2) * (m - 2 * y + 2);
    }
    cout << fin;
  }
  return 0;
}
