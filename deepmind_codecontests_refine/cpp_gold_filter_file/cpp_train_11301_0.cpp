#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, x;
  cin >> a >> b >> c >> d >> x;
  a = max(a, c);
  b = min(b, d);
  if (a > b) {
    cout << 0;
    return 0;
  } else if (x >= a && x <= b)
    cout << b - a;
  else
    cout << b - a + 1;
  return 0;
}
