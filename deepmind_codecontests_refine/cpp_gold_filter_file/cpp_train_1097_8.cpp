#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  int x = 0, y = 0, z = 0;
  int forces[10000];
  cin >> n;
  for (i = 0; i < 3 * n; i++) {
    cin >> forces[i];
  }
  for (i = 0; i < 3 * n; i = i + 3) {
    x += forces[i];
  }
  for (i = 1; i < 3 * n; i = i + 3) {
    y += forces[i];
  }
  for (i = 2; i < 3 * n; i = i + 3) {
    x += forces[i];
  }
  if ((x == 0) && (y == 0) && (z == 0)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
