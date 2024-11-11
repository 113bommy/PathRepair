#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, x;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x == 1) {
        if (i == 0 || i == n - 1 || j == m - 1 || j == 0) {
          cout << 2;
          return 0;
        }
      }
    }
  }
  cout << 4;
}
