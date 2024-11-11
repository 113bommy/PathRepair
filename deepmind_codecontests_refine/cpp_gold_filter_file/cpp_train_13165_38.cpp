#include <bits/stdc++.h>
inline int Rand() { return (rand() << 16) | rand(); }
using namespace std;
const int N = 200005;
const double eps = 1e-9;
int d[20];
int main() {
  d[0] = 2;
  d[1] = 7;
  d[2] = 2;
  d[3] = 3;
  d[4] = 3;
  d[5] = 4;
  d[6] = 2;
  d[7] = 5;
  d[8] = 1;
  d[9] = 2;
  char x, y;
  cin >> x >> y;
  cout << d[x - '0'] * d[y - '0'];
  return 0;
}
