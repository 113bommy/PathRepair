#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 0) {
      cout << 2 << " " << n - 3 << " " << 1 << endl;
    } else {
      if (n % 3 == 1) {
        if ((n - 1) % 4 == 0) {
          cout << (n - 1) / 2 - 1 << " " << (n - 1) / 2 + 1 << " " << 1 << endl;
        } else {
          cout << (n - 1) / 2 - 2 << " " << (n - 1) / 2 + 2 << " " << 1 << endl;
        }
      } else {
        cout << n - 4 << " " << 3 << " " << 1 << endl;
      }
    }
  }
}
