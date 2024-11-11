#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int a = sqrt(x * y / z);
  int b = sqrt(y * z / x);
  int c = sqrt(x * y / z);
  cout << 4 * (a + b + c);
}
