#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "O-|-OOOO";
    return 0;
  }
  int d;
  while (n > 0) {
    d = n % 10;
    if (d < 5) {
      cout << "O-|";
      for (int i = 0; i < d; i++) cout << "O";
      if (4 - d >= 0) {
        cout << "-";
        for (int i = 0; i < 4 - d; i++) cout << "O";
      }
    } else if (d == 5) {
      cout << "-O|-OOOO";
    } else {
      cout << "-O|";
      d -= 5;
      for (int i = 0; i < d; i++) cout << "O";
      if (4 - d >= 0) {
        cout << "-";
        for (int i = 0; i < 4 - d; i++) cout << "O";
      }
    }
    n /= 10;
    cout << "\n";
  }
  return 0;
}
