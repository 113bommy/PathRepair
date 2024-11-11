#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int x;
  int y;
  int z;
  x = a / 10;
  y = (a % 100) * 10 + a % 10;
  z = max(max(x, y), a);
  cout << z << "\n";
  return 0;
}
