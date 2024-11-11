#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
      cout << "P";
      if (i != x - 1) {
        if (i == 0)
          cout << "RL";
        else
          cout << "LR";
      }
    }
    if (i != n - 1) cout << 'R';
  }
}
