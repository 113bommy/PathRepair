#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100005];
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    if (a[0] == a[2]) {
      long long int x = 3;
      for (int i = 3; i < n; i++) {
        if (a[i] != a[0]) {
          break;
        } else {
          x++;
        }
      }
      cout << x * (x - 1) * (x - 2) / 6 << endl;
      continue;
    }
    if (a[0] != a[1] && a[1] != a[2]) {
      long long int x = 1;
      for (int i = 3; i < n; i++) {
        if (a[i] != a[2]) {
          break;
        } else {
          x++;
        }
      }
      cout << x << endl;
      continue;
    }
    if (a[0] != a[1] && a[1] == a[2]) {
      long long int x = 2;
      for (int i = 3; i < n; i++) {
        if (a[i] != a[0]) {
          break;
        } else {
          x++;
        }
      }
      cout << x * (x - 1) / 2 << endl;
      continue;
    }
    if (a[0] == a[1] && a[0] != a[2]) {
      long long int x = 1;
      for (int i = 3; i < n; i++) {
        if (a[i] != a[0]) {
          break;
        } else {
          x++;
        }
      }
      cout << x << endl;
    }
  }
  return 0;
}
