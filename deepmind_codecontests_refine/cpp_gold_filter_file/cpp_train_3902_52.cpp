#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, i, j, x = 3;
  cin >> n >> p;
  int a[n][p];
  for (i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      x--;
    }
    for (j = 1; j <= p; j++) {
      if (i % 2 != 0) {
        cout << "#";
      } else if (i % 2 == 0 && j == p && (x % 2 != 0)) {
        cout << "#";
      } else if (i % 2 == 0 && j == 1 && (x % 2 == 0)) {
        cout << "#";
      } else if (i % 2 == 0 && j <= p) {
        cout << ".";
      }
    }
    x++;
    cout << endl;
  }
}
