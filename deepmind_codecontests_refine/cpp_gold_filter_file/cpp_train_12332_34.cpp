#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main() {
  int t[5];
  for (int i = 0; i < 5; i++) cin >> t[i];
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "S") {
      a[i] = 0;
    } else if (x == "M")
      a[i] = 1;
    else if (x == "L")
      a[i] = 2;
    else if (x == "XL")
      a[i] = 3;
    else
      a[i] = 4;
  }
  for (int i = 0; i < n; i++) {
    int x = a[i];
    for (int e = 0; x + e < 5 || x - e >= 0; e++) {
      if (x + e < 5 && t[x + e] > 0) {
        t[x + e]--;
        if (x + e == 0) {
          cout << "S"
               << "\n";
          break;
        } else if (x + e == 1) {
          cout << "M"
               << "\n";
          break;
        } else if (x + e == 2) {
          cout << "L"
               << "\n";
          break;
        } else if (x + e == 3) {
          cout << "XL"
               << "\n";
          break;
        } else {
          cout << "XXL"
               << "\n";
          break;
        }
      }
      if (x - e >= 0 && t[x - e] > 0) {
        t[x - e]--;
        if (x - e == 0) {
          cout << "S"
               << "\n";
          break;
        } else if (x - e == 1) {
          cout << "M"
               << "\n";
          break;
        } else if (x - e == 2) {
          cout << "L"
               << "\n";
          break;
        } else if (x - e == 3) {
          cout << "XL"
               << "\n";
          break;
        } else {
          cout << "XXL"
               << "\n";
          break;
        }
      }
    }
  }
}
