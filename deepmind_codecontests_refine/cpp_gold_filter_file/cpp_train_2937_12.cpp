#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  if (r == 1 && c == 1)
    cout << "0" << endl;
  else if (c == 1 && r != 1) {
    int x = 2;
    for (int i = 1; i <= r; i++) {
      cout << x << endl;
      x++;
    }
  } else {
    int x = r + 1, y = r + 1;
    for (int i = 1; i <= r; i++) {
      x = y * i;
      for (int j = 1; j <= c; j++) {
        cout << x << " ";
        x = x + i;
      }
      cout << endl;
    }
  }
}
