#include <bits/stdc++.h>
using namespace std;
int main() {
  int tests = 1;
  while (tests--) {
    int n, m;
    cin >> n >> m;
    if (m > n) {
      cout << -1 << endl;
    } else {
      int i = m;
      while (true) {
        if (i >= n / 2) {
          break;
        }
        i += m;
      }
      cout << i << endl;
    }
  }
}
