#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, i, j, k;
  cin >> m >> n;
  for (j = 1; j <= n; j++) {
    if (j % 2 != 0) {
      k = 1;
      while (k <= m) {
        cout << "#";
        k++;
      }
      cout << "\n";
      continue;
    }
    if (j % 2 == 0) {
      if (j % 4 == 0) {
        k = 2;
        cout << "#";
        while (k <= m) {
          cout << ".";
          k++;
        }
        cout << "\n";
        continue;
      } else {
        k = 1;
        while (k < m) {
          cout << ".";
          k++;
        }
        if (k == m) cout << "#";
        cout << "\n";
      }
    }
  }
  return 0;
}
