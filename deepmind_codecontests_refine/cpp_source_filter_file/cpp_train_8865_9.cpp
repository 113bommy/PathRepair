#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    bool win = true;
    if (k % 3 == 0) {
      int np = n % (k + 1);
      if (np % 3 == 0 && n != k) {
        win = false;
      }
    } else {
      int np = n % 3;
      if (np == 0) {
        win = false;
      }
    }
    cout << (win ? "Alice" : "Bob") << endl;
  }
}
