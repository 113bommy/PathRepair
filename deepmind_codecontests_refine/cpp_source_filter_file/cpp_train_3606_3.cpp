#include <bits/stdc++.h>
using namespace std;
int n, a[1000], x, y;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= (a[i] / 2); j++) {
      if (j == sqrt(a[i])) {
        x++;
        break;
      }
    }
    if (x == 0) {
      cout << a[i];
      break;
    }
    x = 0;
  }
  return 0;
}
