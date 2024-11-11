#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, b, c, d, i;
  cin >> n >> k >> a >> b >> c >> d;
  if (n > k || n <= 4) {
    cout << "-1" << endl;
    return 0;
  } else {
    cout << a << " " << c;
    for (i = 1; i <= n; i++) {
      if (i != a && i != b && i != c && i != d) cout << " " << i;
    }
    cout << " " << d << " " << b << endl;
    cout << c << " " << a;
    for (i = 1; i <= n; i++) {
      if (i != a && i != b && i != c && i != d) cout << " " << i;
    }
    cout << " " << b << " " << d << endl;
  }
  return 0;
}
