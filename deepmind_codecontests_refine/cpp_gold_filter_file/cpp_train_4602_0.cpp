#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int o = 0; o < t; ++o) {
    long long n, m, sum = 0, a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    int a[100000], b[100000];
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cin >> m;
    for (int j = 0; j < m; ++j) {
      cin >> b[j];
    }
    for (int k = 0; k < n; ++k) {
      if (!(a[k] % 2)) {
        a2++;
      } else
        a1++;
    }
    for (int l = 0; l < m; ++l) {
      if (!(b[l] % 2)) {
        b2++;
      } else {
        b1++;
      }
    }
    cout << a1 * b1 + a2 * b2 << endl;
  }
  return 0;
}
