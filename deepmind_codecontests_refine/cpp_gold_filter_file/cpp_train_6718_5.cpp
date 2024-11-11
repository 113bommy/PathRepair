#include <bits/stdc++.h>
using namespace std;
int main() {
  int f, i, t;
  cin >> f >> i >> t;
  int a[i];
  for (int k = 1; k <= i; k++) {
    a[k] = 0;
  }
  char y;
  for (int j = 1; j <= f; j++) {
    for (int k = 1; k <= i; k++) {
      cin >> y;
      if (y == 'Y') {
        a[k] = a[k] + 1;
      }
    }
  }
  int s = 0;
  for (int k = 1; k <= i; k++) {
    if (a[k] >= t) {
      s = s + 1;
    }
  }
  cout << s;
  return 0;
}
