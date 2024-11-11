#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int c[t];
  for (int i = 0; i < t; i++) {
    long long a, b, n, k;
    cin >> a >> b >> n;
    if (a > b) {
      b += a;
    } else {
      a += b;
    }
    for (k = 1; a <= n && b <= n; k++) {
      if (k % 2 == 0) {
        a += b;
      } else {
        b += a;
      }
    }
    c[i] = k;
  }
  for (int i = 0; i < t; i++) {
    cout << c[i] << endl;
  }
  return 0;
}
