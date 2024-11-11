#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d[10], t = 0, n, x, i, r = 0;
  cin >> a >> b;
  while (a != b + 1) {
    t = 0;
    for (i = 0; i < 10; i++) d[i] = 0;
    x = a;
    while (x) {
      c = x % 10;
      d[c]++;
      if (d[c] > 1) {
        t = 1;
        break;
      }
      x /= 10;
    }
    if (t == 0) {
      break;
    }
    a++;
  }
  for (i = 0; i < 10; i++) {
    if (d[i] > 1) r = 1;
  }
  if (r == 1)
    cout << "-1";
  else
    cout << a;
  return 0;
}
