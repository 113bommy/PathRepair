#include <bits/stdc++.h>
using namespace std;
int main() {
  string a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  for (int i = 1; i < 13; i++) {
    if (a1[0] == 'X') {
      a1[0] = a1[1];
      a1[1] = 'X';
    } else if (a1[1] == 'X') {
      a1[1] = a2[1];
      a2[1] = 'X';
    } else if (a2[0] == 'X') {
      a2[0] = a1[0];
      a1[0] = 'X';
    } else {
      a2[1] = a2[0];
      a2[0] = 'X';
    }
    if (a1 == b1 && a2 == b2) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
