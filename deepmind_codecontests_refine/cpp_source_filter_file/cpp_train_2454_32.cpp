#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, total = 0;
  cin >> a >> b >> c;
  if (b - 2 * a < 0 || c - 4 * a < 0) {
    a = a - 1;
  }
  if (a * 2 > b || a * 4 > c) {
    total = 0;
    cout << total << endl;
  } else {
    total = a + a * 2 + a * 4;
    cout << total << endl;
  }
  return 0;
}
