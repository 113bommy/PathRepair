#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int result1, result2;
  if (f > e) {
    int mn = min(b, min(c, d));
    result1 = mn * f;
    d = d - mn;
    int m = min(d, a);
    result2 = m * e;
    cout << result1 + result2 << endl;
  } else {
    int mn = min(a, d);
    result1 = mn * e;
    d = d - mn;
    int m = min(d, min(b, c));
    result2 = m * f;
    cout << result1 + result2 << endl;
  }
}
