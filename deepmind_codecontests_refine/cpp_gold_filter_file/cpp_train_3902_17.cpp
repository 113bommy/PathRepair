#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, i, j, o = 0;
  cin >> r >> c;
  for (i = 0; i < r; i++) {
    if (i % 2 == 0) {
      for (j = 0; j < c; j++) {
        cout << "#";
      }
    } else {
      o++;
      for (j = 0; j < c; j++) {
        if (o % 2 == 1 && j == c - 1)
          cout << "#";
        else if (o % 2 == 0 && j == 0)
          cout << "#";
        else
          cout << ".";
      }
    }
    cout << "\n";
  }
}
