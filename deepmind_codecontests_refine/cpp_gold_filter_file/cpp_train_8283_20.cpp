#include <bits/stdc++.h>
using namespace std;
int main() {
  bool a, b, c, d, z;
  cin >> a >> b >> c >> d;
  z = ((a ^ b) & (c | d)) ^ ((b & c) | (a ^ d));
  cout << z;
  return 0;
}
