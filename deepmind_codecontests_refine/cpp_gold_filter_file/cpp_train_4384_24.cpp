#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 1, sum = 0, a[3], w, h;
  cin >> a[0] >> a[1] >> a[2];
  h = a[0];
  w = a[1];
  while (i <= a[2]) {
    sum = (2 * w) + 2 * (h - 2) + sum;
    w = w - 4;
    h = h - 4;
    i = i + 1;
  }
  cout << sum;
  return 0;
}
