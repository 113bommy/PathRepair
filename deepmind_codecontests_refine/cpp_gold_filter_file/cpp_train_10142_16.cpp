#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c = 0, d = 0, e = 0;
  cin >> a >> b;
  for (int i = 1; i <= 6; i++) {
    if (a >= i && b >= i) {
      if ((a - i) < (b - i))
        c++;
      else if ((a - i) == (b - i))
        d++;
      else
        e++;
    } else if (a <= i && b <= i) {
      if ((i - a) < (i - b))
        c++;
      else if ((i - a) == (i - b))
        d++;
      else
        e++;
    } else if (a >= i && b <= i) {
      if ((a - i) < (i - b))
        c++;
      else if ((a - i) == (i - b))
        d++;
      else
        e++;
    } else {
      if ((i - a) < (b - i))
        c++;
      else if ((i - a) == (b - i))
        d++;
      else
        e++;
    }
  }
  cout << c << " " << d << " " << e;
  return 0;
}
