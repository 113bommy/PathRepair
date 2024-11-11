#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, k;
  cin >> q;
  while (q--) {
    cin >> k;
    if (k % 2 == 0) {
      cout << "0"
           << "\n";
    } else if (k == 2) {
      cout << "2"
           << "\n";
    } else {
      cout << "1"
           << "\n";
    }
  }
}
