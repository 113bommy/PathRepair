#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, z;
  cin >> n;
  if (n % 3 == 2) {
    x = 1;
    y = 2;
    z = n - 3;
  } else {
    x = 1;
    y = 1;
    z = n - 2;
  }
  cout << x << " " << y << " " << z << endl;
  return 0;
}
