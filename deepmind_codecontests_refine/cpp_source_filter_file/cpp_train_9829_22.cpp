#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      if (t == 1) {
        if (i == 0 || j == 0 || i == n || j == m) {
          cout << 2;
          return 0;
        }
      }
    }
  }
  cout << 4;
  return 0;
}
