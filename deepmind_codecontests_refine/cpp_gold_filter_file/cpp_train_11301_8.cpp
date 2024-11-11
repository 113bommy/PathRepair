#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  if (c <= b && d >= a) {
    a = max(a, c);
    b = min(b, d);
    if (a <= e && e <= b) b--;
    cout << b - a + 1 << endl;
  } else
    cout << 0 << endl;
  return 0;
}
