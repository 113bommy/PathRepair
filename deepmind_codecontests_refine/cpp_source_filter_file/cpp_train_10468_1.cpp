#include <bits/stdc++.h>
using namespace std;
bool checkcorner(string pos) {
  string corners[] = {"a1", "a8", "h1", "h8"};
  for (int i = 0; i < 4; i++) {
    if (pos == corners[i]) {
      return true;
      break;
    }
  }
  return false;
}
bool checkside(string a, string b) {
  if (a == "1" || a == "8" || b == "a" || b == "h") {
    return true;
  }
  return false;
}
int main() {
  string cd;
  string c, d;
  int test(0);
  cin >> cd;
  c = cd[1];
  d = cd[2];
  if (checkcorner(cd)) {
    cout << 3;
  } else if (checkside(d, c)) {
    cout << 5;
  } else {
    cout << 8;
  }
}
