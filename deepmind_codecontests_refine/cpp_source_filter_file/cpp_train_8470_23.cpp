#include <bits/stdc++.h>
using namespace std;
bool check(string x) {
  bool q = true;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (x.at(i) == x.at(j)) {
        q = false;
      }
    }
  }
  return q;
}
int main() {
  int y;
  cin >> y;
  string x;
  for (int i = 1; i < 100; i++) {
    y += 1;
    string z = to_string(y);
    if (check(z) == 1) {
      x = z;
      break;
    }
  }
  cout << x;
}
