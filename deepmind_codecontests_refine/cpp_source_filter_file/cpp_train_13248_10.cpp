#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a == 1) {
        cout << 1 << "\n";
      }
      if (a == 2) {
        cout << 2 << "\n";
      } else if (a % 2 == 0) {
        cout << a / 2 + 1 << "\n";
      } else {
        cout << (a + 1) / 2 << "\n";
      }
    }
  }
}
