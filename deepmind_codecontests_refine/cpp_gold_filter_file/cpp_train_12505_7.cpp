#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m, x;
  cin >> x;
  for (i = 1; i <= x; i++) {
    for (j = 1; j <= x; j++) {
      if (i % j == 0 && i / j < x && i * j > x) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
