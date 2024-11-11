#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, a;
  cin >> x;
  if (x <= 3) {
    if (x == 1) {
      a = 1;
    } else if (x == 2) {
      a = 2;
    } else {
      a = 3;
    }
  } else {
    int i;
    for (i = 1; i <= 100; i += 2) {
      if (i * i / 2 + 1 >= x) {
        break;
      }
    }
    a = i;
  }
  cout << a << endl;
  return 0;
}
