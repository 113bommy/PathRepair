#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, z = 1, t;
  cin >> x;
  if (x == 3) {
    cout << "3";
    return 0;
  } else {
    while (x > z * z / 2 + 1) z += 2;
    cout << z;
  }
}
