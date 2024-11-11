#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f = 0, z = 0, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 5) {
      f++;
    } else if (x == 0) {
      z++;
    }
  }
  if (f >= 9 && z > 0) {
    for (int i = 0; i < f - (f % 9); i++) {
      cout << 5;
    }
    for (int j = z; j > 0; j--) {
      cout << 0;
    }
  } else if (z > 0 && f < 9) {
    cout << 0;
  } else
    cout << -1;
  return 0;
}
