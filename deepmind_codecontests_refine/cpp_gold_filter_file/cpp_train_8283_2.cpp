#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const long long INF = 1e18;
const int mod = 1e4 + 7;
int main() {
  bool a, b, c, d;
  bool x0, x1, x2, x3, x4, x5, x6;
  cin >> a >> b >> c >> d;
  x0 = a ^ b;
  x1 = c | d;
  x2 = b & c;
  x3 = a ^ d;
  x4 = x0 & x1;
  x5 = x2 | x3;
  x6 = x4 ^ x5;
  cout << x6 << endl;
}
