#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < n / 2; j++) cout << "WB";
      if (n % 2 == 1) {
        cout << "W";
      }
    } else {
      for (int j = 0; j < n / 4; j++) {
        cout << "BBBW";
      }
      if (n % 4 == 1) {
        cout << "B";
      }
      if (n % 4 == 2) {
        cout << "BB";
      }
      if (n % 4 == 3) {
        cout << "BBB";
      }
    }
    cout << endl;
  }
}
