#include <bits/stdc++.h>
int a[1005], n, x, y, z, t, k;
using namespace std;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      if (a[i] <= a[i + 1]) {
        x = a[i];
        y = a[i + 1];
      } else {
        x = a[i + 1];
        y = a[i];
      }
      if (a[j] <= a[j + 1]) {
        z = a[j];
        t = a[j + 1];
      } else {
        z = a[j + 1];
        t = a[j];
      }
      if (x < z && z < y) {
        if (t > y) {
          cout << "yes";
          return 0;
        }
      }
      if (z < x) {
        if (x < t < y) {
          cout << "yes";
          return 0;
        }
      }
    }
  }
  cout << "no";
  return 0;
}
