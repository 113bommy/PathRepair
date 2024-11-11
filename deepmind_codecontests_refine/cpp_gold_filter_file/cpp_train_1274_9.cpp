#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, a[1000000], i, j, k, s, l, m;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    s = a[0];
    k = 0;
    for (i = 1; i < n; i++) {
      if (s < 0 && a[i] < 0) {
        if (s < a[i]) s = a[i];
      } else if (s >= 0 && a[i] >= 0) {
        if (s < a[i]) s = a[i];
      } else {
        k = k + s;
        s = a[i];
      }
    }
    k = k + s;
    cout << k << endl;
  }
}
