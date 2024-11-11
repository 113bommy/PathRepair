#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int u1 = 0, v1 = 0, u2 = 0, v2 = 0;
  int x, y, z;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    if (x == 1) {
      u1 += y;
      v1 += z;
    }
    if (x == 2) {
      u2 += y;
      v2 += z;
    }
  }
  if (u1 - v1 >= 0) {
    cout << "LIVE";
  } else {
    cout << "DEAD";
  }
  if (u2 - v2 >= 0) {
    cout << "\nLIVE";
  } else {
    cout << "\nDEAD";
  }
  return 0;
}
