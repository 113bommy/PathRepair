#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  if (k > 36) {
    cout << -1 << endl;
  } else {
    while (k > 0) {
      if (k - 2 >= 0) {
        cout << 8;
        k -= 2;
      } else if (k - 1 >= 0) {
        cout << 6;
        k -= 1;
      }
    }
  }
  return 0;
}
