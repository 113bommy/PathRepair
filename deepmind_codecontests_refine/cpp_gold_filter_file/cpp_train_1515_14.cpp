#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5], i, b = -1, c = 0, sum = 0, small = 1000;
  for (i = 0; i < 5; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int p;
  sort(a, a + 5);
  for (i = 3; i >= 0; i--) {
    p = sum;
    if (a[i] == a[i + 1]) {
      if (a[i - 1] == a[i]) {
        p -= 3 * a[i];
      } else {
        p -= 2 * a[i];
      }
    }
    if (p < small) small = p;
  }
  cout << small;
  return 0;
}
