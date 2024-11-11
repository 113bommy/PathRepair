#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  int x1 = a & b, x2 = c | d, x3 = b ^ c, x4 = a & d;
  int x5 = x1 ^ x2, x6 = x3 | x4;
  cout << (x5 & x6) << endl;
  return 0;
}
