#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[7];
  for (int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  int k = n;
  int i = 0;
  while (i < (7 * n)) {
    if (i % 7 == 0) {
      k = k - a[i % 7];
      if (k <= 0) break;
    }
    if (i % 7 == 1) {
      k = k - a[i % 7];
      if (k <= 0) break;
    }
    if (i % 7 == 2) {
      k = k - a[i % 7];
      if (k <= 0) break;
    }
    if (i % 7 == 3) {
      k = k - a[i % 7];
      if (k <= 0) break;
    }
    if (i % 7 == 4) {
      k = k - a[i % 7];
      if (k <= 0) break;
    }
    if (i % 7 == 5) {
      k = k - a[i % 7];
      if (k <= 0) break;
    }
    if (i % 7 == 6) {
      k = k - a[i % 7];
      if (k <= 0) break;
    }
    i++;
  }
  cout << (i % 7) + 1 << endl;
  return 0;
}
