#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, z;
  string i, y;
  i = "ouieay";
  cin >> y;
  for (x = 0; x <= y.size(); x++) {
    y[x] = tolower(y[x]);
    for (z = 0; z <= i.size(); z++) {
      if (y[x] == i[z]) {
        y[x] = '.';
        break;
      }
    }
  }
  for (x = 0; x < y.size(); x++) {
    if (y[x] != '.') {
      cout << "." << y[x];
    }
  }
  return 0;
}
