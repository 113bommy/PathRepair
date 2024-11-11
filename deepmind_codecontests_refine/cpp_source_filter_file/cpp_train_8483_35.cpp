#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1, c2;
  cin >> c1 >> c2;
  if (c1 > c2) {
    cout << c2 << " ";
    if ((c1 - c2) % 2 == 0) {
      cout << (c1 - c2) / 2;
    } else if ((c1 - c2) == 1) {
      cout << 0;
    } else {
      cout << c1 - c2 - 1;
    }
  } else if (c2 > c1) {
    cout << c1 << " ";
    if ((c2 - c1) % 2 == 0) {
      cout << (c2 - c1) / 2;
    } else if ((c2 - c1) == 1) {
      cout << 0;
    } else {
      cout << (c2 - c1 - 1) / 2;
    }
  } else {
    cout << c1 << " " << 0;
  }
}
