#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a[7];
  while (t--) {
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
      if (a[i] + a[i + 1] + a[i + 2] == a[6]) {
        cout << a[i] << " " << a[i + 1] << " " << a[i + 2];
        break;
      } else if (a[i] + a[i + 1] + a[i + 3] == a[6]) {
        cout << a[i] << " " << a[i + 1] << " " << a[i + 3];
        break;
      }
    }
    cout << endl;
  }
}
