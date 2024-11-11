#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, z;
  cin >> n;
  z = n - 10;
  if (z == 1) {
    cout << 4;
    return 0;
  }
  if (z >= 2 && z <= 9) {
    cout << 4;
    return 0;
  }
  if (z == 10) {
    cout << 15;
    return 0;
  }
  if (z == 11) {
    cout << 1;
    return 0;
  }
  cout << 0;
}
