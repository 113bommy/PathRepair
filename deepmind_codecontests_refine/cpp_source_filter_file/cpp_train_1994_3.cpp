#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num, d;
  cin >> n;
  int a[3];
  int state = 0;
  for (int i = 0; i < n; i++) {
    cin >> num;
    switch (state) {
      case 0:
        a[0] = num;
        state = 1;
        break;
      case 1:
        if (num != a[0]) {
          a[1] = num;
          state = 2;
        }
        break;
      case 2:
        if (num != a[0] && num != a[1]) {
          a[2] = num;
          state = 3;
        }
        break;
      case 3:
        if (num != a[0] && num != a[1] && num != a[2]) {
          d = -1;
          state = 0;
        }
        break;
    }
  }
  if (state == 1) {
    d = 0;
  } else if (state == 2) {
    d = abs(a[1] - a[0]);
    if (d % 2 == 0) {
      d = d / 2;
    }
  } else if (state == 3) {
    sort(a, a + 3);
    if ((a[1] - a[0]) == (a[2] - a[1])) {
      d = a[1] - a[0];
    } else {
      d = -1;
    }
  }
  cout << d;
  return (0);
}
