#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int count = 0, c = 0;
  if (a != 0 && b != 0) {
    while (a != 0 && b != 0) {
      a--;
      b--;
      count++;
    }
    cout << count;
  }
  if (a != 0) {
    while (a > 0) {
      if (a % 2 == 0) {
        a = a - 2;
        c++;
      } else {
        break;
      }
    }
  } else if (b != 0) {
    while (b > 0) {
      if (b % 2 == 0) {
        b = b - 2;
        c++;
      } else {
        break;
      }
    }
  }
  cout << " " << c;
  return 0;
}
