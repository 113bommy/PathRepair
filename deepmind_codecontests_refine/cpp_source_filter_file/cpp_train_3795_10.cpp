#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int h = n / 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i <= h) {
        if (j >= h - i && j <= h + i) {
          cout << 'D';
        } else {
          cout << '.';
        }
      } else {
        if (j >= i - h && j <= 3 * n / 2 - 1 - i) {
          cout << 'D';
        } else {
          cout << '*';
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
