#include <bits/stdc++.h>
using namespace std;
int main() {
  string st[20];
  char z[7];
  int purple = 1, blue = 2, green = 3, red = 4, orange = 5, yellow = 6,
      a[7] = {0};
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> st[i];
    if (st[i] == "purple") {
      a[purple] += 1;
    } else if (st[i] == "green") {
      a[green] += 3;
    } else if (st[i] == "blue") {
      a[blue] += 2;
    } else if (st[i] == "red") {
      a[red] += 4;
    } else if (st[i] == "orange") {
      a[orange] += 5;
    } else if (st[i] == "yellow") {
      a[yellow] += 6;
    }
  }
  cout << 6 - n << "\n";
  for (int i = 1; i <= 6; i++) {
    if (a[i] == 0) {
      if (i == 1) {
        cout << "Power"
             << "\n";
      }
      if (i == 2) {
        cout << "Time"
             << "\n";
      }
      if (i == 3) {
        cout << "Space"
             << "\n";
      }
      if (i == 4) {
        cout << "Reality"
             << "\n";
      }
      if (i == 5) {
        cout << "Soul"
             << "\n";
      }
      if (i == 6) {
        cout << "Mind"
             << "\n";
      }
    }
  }
  return 0;
}
