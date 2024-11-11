#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int z = 0, f = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      z++;
    } else {
      f++;
    }
  }
  if (z == 0) {
    cout << -1;
    return 0;
  } else if (z >= 1) {
    int q = f / 9;
    if (q == 0) {
      cout << 0;
      return 0;
    }
    int rem = f % 9;
    f -= rem;
    for (int i = 0; i < f; i++) {
      cout << 5;
    }
    for (int i = 0; i < z; i++) {
      cout << 0;
    }
  }
}
