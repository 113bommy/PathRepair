#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[20], x, y, z;
  for (int i = 0; i < 9; i++) {
    cin >> m[i];
  }
  x = m[1] + m[2];
  y = m[3] + m[5];
  z = m[6] + m[7];
  m[0] = (y + z - x) / 2;
  m[4] = (x + z - y) / 2;
  m[8] = (x + y - z) / 2;
  for (int i = 0; i < 3; i++) {
    cout << m[i] << " ";
    if (i == 2 || i == 5 || i == 8) cout << endl;
  }
  return 0;
}
