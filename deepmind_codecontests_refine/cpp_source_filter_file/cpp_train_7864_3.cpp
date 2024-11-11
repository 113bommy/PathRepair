#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, v[93];
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> v[i];
  }
  if (n > 2) {
    if (v[n] == 0) {
      cout << "UP";
    } else if (v[n] == 15) {
      cout << "DOWN";
    } else {
      if (v[n] > v[n - 1]) {
        cout << "UP";
      } else {
        cout << "DOWN";
      }
    }
  }
  if (n < 2) {
    if (v[n] == 15) {
      cout << "DOWN";
    }
    if (v[n] == 0) {
      cout << "UP";
    }
    if (v[n] != 0 && v[n] != 15) {
      cout << -1;
    }
  }
  return 0;
}
