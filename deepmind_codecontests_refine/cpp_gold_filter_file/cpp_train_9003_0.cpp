#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, a, b, count = 0;
  cin >> x;
  if (x == 1 || x == 2) {
    cout << 1;
    return 0;
  }
  while (x >= 1) {
    a = 2;
    while (a <= x) {
      a *= 2;
    }
    a /= 2;
    x = x - a;
    ++count;
  }
  cout << count;
  return 0;
}
