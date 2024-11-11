#include <bits/stdc++.h>
using namespace std;
int x, y;
void tes(int a, int b, int c, int d) {
  cout << a << b << c << d << endl;
  cin >> x >> y;
}
int a[10], maks;
int main() {
  maks = -1;
  for (int i = 0; i <= 9; i++) {
    tes(i, 0, 0, 0);
    if (x > maks) {
      maks = x;
      a[1] = i;
    }
  }
  maks = -1;
  for (int i = 0; i <= 9; i++) {
    tes(0, i, 0, 0);
    if (x > maks) {
      maks = x;
      a[2] = i;
    }
  }
  maks = -1;
  for (int i = 0; i <= 9; i++) {
    tes(0, 0, i, 0);
    if (x > maks) {
      maks = x;
      a[3] = i;
    }
  }
  maks = -1;
  for (int i = 0; i <= 9; i++) {
    tes(0, 0, 0, i);
    if (x > maks) {
      maks = x;
      a[4] = i;
    }
  }
  cout << a[1] << a[2] << a[3] << a[4] << endl;
  cin >> x >> y;
  return 0;
}
