#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int last;
    cin >> last;
    bool strictly_increasing = true;
    for (int j = 1; j < n; j++) {
      int x;
      cin >> x;
      if (x <= last) {
        strictly_increasing = false;
      }
      last = x;
    }
    if (n % 2 == 0 || !strictly_increasing) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
