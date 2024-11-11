#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  unsigned long long int a, b, c, d, p, e;
  while (t--) {
    cin >> a >> b >> c >> d;
    if (a <= b)
      cout << b << endl;
    else {
      if (d >= c)
        cout << -1 << endl;
      else {
        p = c - d;
        e = (a - b) / p;
        if ((e * p) < (a - b))
          cout << b + ((e + 1) * c) << endl;
        else
          cout << b + (e * c) << endl;
      }
    }
  }
}
