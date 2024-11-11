#include <bits/stdc++.h>
using namespace std;
int detectNum(int a) {
  if (a == 0) return 2;
  if (a == 1) return 7;
  if (a == 2) return 2;
  if (a == 3) return 3;
  if (a == 4) return 3;
  if (a == 5) return 4;
  if (a == 6) return 2;
  if (a == 7) return 6;
  if (a == 8) return 1;
  if (a == 9) return 2;
}
int main() {
  int m, x, y;
  cin >> m;
  x = m / 10;
  y = (m - x * 10);
  cout << detectNum(x) * detectNum(y);
  return 0;
}
