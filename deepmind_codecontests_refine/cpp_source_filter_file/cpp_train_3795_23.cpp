#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, s, k = 0, i, d;
  cin >> r;
  d = (r / 2) + 1;
  for (i = 1; i <= d; i++, k = 0) {
    for (s = 1; s <= d - i; s++) {
      cout << "* ";
    }
    while (k != 2 * i - 1) {
      cout << "D ";
      k++;
    }
    for (s = 1; s <= d - i; s++) {
      cout << "* ";
    }
    cout << endl;
  }
  for (i = d - 1; i >= 1; i--, k = 0) {
    for (s = d - i; s >= 1; s--) {
      cout << "* ";
    }
    while (k != 2 * i - 1) {
      cout << "D ";
      k++;
    }
    for (s = d - i; s >= 1; s--) {
      cout << "* ";
    }
    cout << endl;
  }
  return 0;
}
