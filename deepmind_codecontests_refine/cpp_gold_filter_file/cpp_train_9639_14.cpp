#include <bits/stdc++.h>
using namespace std;
int x, y;
bool Ciel(int &x, int &y) {
  if (x >= 2 && y >= 2) {
    x -= 2;
    y -= 2;
    return true;
  } else if (x >= 1 && y >= 12) {
    x -= 1;
    y -= 12;
    return true;
  } else if (y >= 22) {
    y -= 22;
    return true;
  }
  return false;
}
bool Hanako(int &x, int &y) {
  if (y >= 22) {
    y -= 22;
    return true;
  } else if (x >= 1 && y >= 12) {
    x -= 1;
    y -= 12;
    return true;
  } else if (x >= 2 && y >= 2) {
    x -= 2;
    y -= 2;
    return true;
  }
  return false;
}
int main() {
  cin >> x >> y;
  while (true) {
    if (!Ciel(x, y)) {
      cout << "Hanako" << endl;
      return 0;
    }
    if (!Hanako(x, y)) {
      cout << "Ciel" << endl;
      return 0;
    }
  }
}
