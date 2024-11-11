#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int d = y - z;
  if (d > 1) cout << "<<";
  for (int i = (y - z); i < y; i++) {
    if (i > 0) cout << i << " ";
  }
  cout << "(" << y << ") ";
  for (int j = (y + 1); j < (y + z + 1); j++) {
    if (j <= x) cout << j << " ";
  }
  if ((y + z) < x) cout << ">>";
  return 0;
}
