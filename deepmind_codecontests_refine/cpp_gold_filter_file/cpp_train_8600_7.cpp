#include <bits/stdc++.h>
using namespace std;
const int INF = 2 * 1e9;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 4 == 1) {
      x -= 9;
      if (x >= 0) {
        cout << x / 4 + 1;
      } else {
        cout << -1;
      }
    } else if (x % 4 == 2) {
      x -= 6;
      if (x >= 0) {
        cout << x / 4 + 1;
      } else {
        cout << -1;
      }
    } else if (x % 4 == 3) {
      x -= 15;
      if (x >= 0) {
        cout << x / 4 + 2;
      } else {
        cout << -1;
      }
    } else {
      cout << x / 4;
    }
    cout << endl;
  }
  return 0;
}
