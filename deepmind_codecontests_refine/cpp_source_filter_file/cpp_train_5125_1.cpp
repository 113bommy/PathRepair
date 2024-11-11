#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int j, y, h, i, d, x, n, k, l, m, p;
    cin >> n >> d;
    int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    h = a[0];
    for (i = 1; i < n; i++) {
      if (d > i && a[i] > 0) {
        j = d / i;
        if (a[i] >= j) {
          h += j;
          d -= i * j;
        } else {
          h += a[i];
          d -= i * a[i];
        }
      }
    }
    cout << h << endl;
  }
}
