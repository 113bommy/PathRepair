#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int r, c, s;
  int t[5][5];
  for (int i(0); i < 5; i++) {
    for (int j(0); j < 5; j++) {
      cin >> t[i][j];
      if (t[i][j] == 1) {
        r = i;
        c = j;
      }
    }
  }
  c = abs((4 - r) + (4 - c));
  cout << c;
  return 0;
}
