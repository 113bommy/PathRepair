#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, x, p, q;
    cin >> a >> b;
    x = abs(a - b);
    if (x > 2) {
      p = x % 5;
      q = x / 5;
      if (p == 0)
        cout << q << endl;
      else if (p < 3)
        cout << q + 1 << endl;
      else
        cout << q + 2 << endl;
    } else
      cout << x << endl;
  }
  return 0;
}
