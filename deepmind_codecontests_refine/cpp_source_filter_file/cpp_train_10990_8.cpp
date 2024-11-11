#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, d, c;
  cin >> m >> d;
  if (m >= 7) m--;
  if (m == 2) {
    if (d <= 1)
      c = 4;
    else
      c = 5;
  } else if (!(m % 2)) {
    if (d <= 6) {
      c = 5;
    } else
      c = 6;
  } else {
    if (d <= 6)
      c = 5;
    else
      c = 6;
  }
  cout << c << endl;
  return 0;
}
