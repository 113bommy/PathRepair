#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c == 0) {
    if (a == d)
      cout << 1;
    else
      cout << 0;
  } else {
    if (a == d && a != 0)
      cout << 1;
    else
      cout << 0;
  }
}
