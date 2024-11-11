#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y;
  z = min(x, y);
  if (z % 2 == 0) {
    cout << "Malvika" << endl;
  } else {
    cout << "Akshat" << endl;
  }
  return 0;
}
