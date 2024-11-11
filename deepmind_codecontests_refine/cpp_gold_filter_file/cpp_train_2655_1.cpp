#include <bits/stdc++.h>
using namespace std;
int n, k, x, z, a[100100], cr = 0, u[100010];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int c;
  while (cr < n) {
    if (x == 0) {
      for (int i = 1; i <= n; ++i) {
        if (z >= a[i] && u[i] == 0) {
          cr++;
          z++;
          u[i] = 1;
        }
      }
      x = 1;
      k++;
    } else {
      for (int i = n; i > 0; i--) {
        if (z >= a[i] && u[i] == 0) {
          cr++;
          z++;
          u[i] = 1;
        }
      }
      x = 0;
      k++;
    }
  }
  cout << k - 1 << endl;
  return 0;
}
