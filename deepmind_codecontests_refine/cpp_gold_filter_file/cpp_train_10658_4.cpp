#include <bits/stdc++.h>
using namespace std;
int main() {
  int TUX;
  cin >> TUX;
  int FOO = 0, BAR = 0, BAZ = 0, QUZ = 1;
  for (int i = 1; i <= TUX; i++) {
    int PUR;
    cin >> PUR;
    FOO = FOO + PUR;
    BAR = BAR + 1;
    if (FOO * QUZ > BAZ * BAR) {
      BAZ = FOO;
      QUZ = BAR;
    }
  }
  cout << BAZ * 1.0 / QUZ;
}
