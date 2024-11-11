#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c, d, q;
  long long es = -1;
  cin >> a >> b >> c >> d;
  if ((b - a) * 2 == (c - a) && (c - a) * 3 == (d - a) * 2) {
    cout << a + 4 * (b - a);
  } else if ((b * b) / (a * a) == (c / a) &&
             (b * b * b) / (a * a * a) == (d / a)) {
    a = a * (b * b * b * b) / (a * a * a * a);
    es = a * (b * b * b * b) / (a * a * a * a);
    if (a == es)
      cout << a;
    else
      cout << 42;
  } else
    cout << 42;
}
