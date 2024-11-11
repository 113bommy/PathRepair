#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  if (r == 1 && c == 1)
    cout << "0" << endl;
  else if (r == 1) {
    for (int i = 2; i <= c + 1; i++) cout << i << " ";
  } else if (c == 1) {
    for (int i = 2; i <= r + 1; i++) cout << i << endl;
  } else {
    for (int i = 1; i <= r; i++) {
      for (int j = r + 1; j <= r + c; j++) {
        cout << i * j << " ";
      }
      cout << endl;
    }
  }
}
