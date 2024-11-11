#include <bits/stdc++.h>
using namespace std;
bool check(int c1, int c2, int c3, int v1, int v2, int v3, int m) {
  return (c1 >= v1 && c1 <= 2 * v1 && c2 >= v2 && c2 <= 2 * v2 && c3 >= v3 &&
          c3 <= 2 * v3 && 2 * m >= c3 && 2 * m <= c2 && c3 < c2 && c2 < c1 &&
          m <= c3);
}
int main() {
  int v1, v2, v3, m;
  cin >> v1 >> v2 >> v3 >> m;
  for (int i = 0; i <= 200; i++) {
    for (int j = i + 1; j <= 200; j++) {
      for (int k = j + 1; k <= 200; k++) {
        if (check(k, j, i, v1, v2, v3, m)) {
          cout << k << endl;
          cout << j << endl;
          cout << i << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
