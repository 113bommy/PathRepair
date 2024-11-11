#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, m, x, y, z, p, k, row, col, a, b, temp;
  cin >> n >> m >> x >> y >> z >> p;
  for (i = 0; i < p; i++) {
    cin >> a >> b;
    if (x % 4 == 0) {
      row = n;
      col = m;
    } else if (x % 4 == 1) {
      temp = a;
      a = b;
      b = n - temp + 1;
      row = m;
      col = n;
    } else if (x % 4 == 2) {
      a = n - a + 1;
      b = m - b + 1;
      row = n;
      col = m;
    } else if (x % 4 == 3) {
      temp = a;
      a = m - b + 1;
      b = temp;
      row = m;
      col = n;
    }
    if (y % 2 == 1) b = col - b + 1;
    if (z % 4 == 1) {
      temp = a;
      a = col - b + 1;
      b = temp;
    } else if (z % 4 == 2) {
      a = row - a + 1;
      b = col - b + 1;
    } else if (z % 4 == 3) {
      temp = a;
      a = b;
      b = row - temp + 1;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
