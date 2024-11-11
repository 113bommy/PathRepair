#include <bits/stdc++.h>
using namespace std;
int p, x, y, i;
bool rec(int x) {
  int temp = (((x / 50)) * 96 + 42) % 475;
  for (int k = 1; k <= 25; k++) {
    if (temp == i) {
      return true;
    }
    temp = (temp * 96 + 42) % 475;
  }
  return false;
}
int main() {
  cin >> p >> x >> y;
  i = p - 26;
  int suc = 0, unsec = 0;
  int z = x;
  if (rec(x)) {
    cout << suc;
    return 0;
  } else {
    while (x - 50 >= y) {
      x -= 50;
      if (rec(x)) {
        cout << suc;
        return 0;
      }
    }
    x = z;
    int c = 0;
    while (1) {
      x += 50;
      c++;
      if (c % 2 != 0) suc++;
      if (rec(x)) {
        cout << suc;
        return 0;
      }
    }
  }
}
