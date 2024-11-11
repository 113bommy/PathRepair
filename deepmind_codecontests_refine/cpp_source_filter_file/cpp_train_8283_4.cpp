#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e[8];
int main() {
  cin >> a >> b >> c >> d;
  e[1] = a ^ b;
  e[2] = c | d;
  e[3] = a & b;
  e[4] = a ^ b;
  e[5] = e[1] & e[2];
  e[6] = e[3] | e[4];
  e[7] = e[5] ^ e[6];
  cout << e[7] << endl;
}
