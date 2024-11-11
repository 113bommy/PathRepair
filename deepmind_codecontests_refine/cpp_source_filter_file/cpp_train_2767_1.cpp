#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6][3];
  a[0][0] = 0;
  a[0][1] = 1;
  a[0][2] = 2;
  a[1][0] = 1;
  a[1][1] = 0;
  a[1][2] = 2;
  a[2][0] = 1;
  a[2][1] = 2;
  a[2][2] = 0;
  a[3][0] = 2;
  a[3][1] = 1;
  a[3][2] = 0;
  a[4][0] = 2;
  a[4][1] = 0;
  a[4][2] = 1;
  a[5][0] = 1;
  a[5][1] = 2;
  a[5][2] = 0;
  int x, y;
  cin >> x >> y;
  cout << a[x % 6][y] << endl;
  return 0;
}
