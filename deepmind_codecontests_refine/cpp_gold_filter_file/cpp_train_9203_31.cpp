#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i;
  int a, b, c, d;
  int m = 0;
  int k;
  int k2, k3;
  for (i = 1; i <= 4; i++) {
    cin >> a >> b >> c >> d;
    if (a + c <= n) {
      m = 1;
      k = i;
      k2 = a;
      k3 = c;
    } else if (a + d <= n) {
      m = 1;
      k = i;
      k2 = a;
      k3 = c;
    } else if (b + c <= n) {
      m = 1;
      k = i;
      k2 = b;
      k3 = c;
    } else if (b + d <= n) {
      m = 1;
      k = i;
      k2 = b;
      k3 = c;
    }
  }
  if (m == 0) {
    cout << -1 << endl;
  } else {
    cout << k << " " << k2 << " " << n - k2 << endl;
  }
}
