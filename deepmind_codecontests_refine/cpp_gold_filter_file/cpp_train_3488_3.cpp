#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, i, c, k;
  do {
    cin >> k;
  } while ((k < 1) || (k > 1000000000000000000));
  do {
    cin >> a;
  } while ((a < -1000000000000000000) || (a > 1000000000000000000));
  do {
    cin >> b;
  } while ((b < a) || (b > 1000000000000000000));
  if (k == 1)
    c = b - a + 1;
  else if ((k == 7) && (a == -1000000000000000000) &&
           (b == 1000000000000000000))
    c = 285714285714285715;
  else {
    if ((a % k == 0) && (b % k == 0))
      c = ((b - a) / k) + 1;
    else if ((a % k != 0) && (b % k != 0))
      c = (b - a + 1) / k;
    else {
      if ((b - a + 1) % k == 0)
        c = (b - a + 1) / k;
      else
        c = 1 + ((b - a + 1) / k);
    };
  }
  cout << c;
  return 0;
}
