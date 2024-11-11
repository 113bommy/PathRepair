#include <bits/stdc++.h>
using namespace std;
int ar[101];
int main() {
  int r, c;
  cin >> r >> c;
  bool b = false;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
          b = true;
          break;
        }
      }
    }
  if (b)
    cout << 2;
  else
    cout << 4;
  return 0;
}
