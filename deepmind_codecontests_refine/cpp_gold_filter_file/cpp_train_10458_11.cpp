#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6] = {};
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  int b[9] = {};
  for (int i = 0; i < 6; i++) {
    b[a[i] - 1]++;
  }
  int legs = 0;
  int e = 0;
  for (int i = 0; i < 9; i++) {
    if (b[i] == 4) {
      legs = 1;
    } else if (b[i] == 6) {
      cout << "Elephant" << endl;
      return 0;
    } else if (b[i] == 5) {
      cout << "Bear" << endl;
      return 0;
    } else if (b[i] == 2) {
      e++;
    }
  }
  if (legs != 1) {
    cout << "Alien" << endl;
  } else if (legs == 1 && e == 1) {
    cout << "Elephant" << endl;
  } else {
    cout << "Bear" << endl;
  }
  return 0;
}
