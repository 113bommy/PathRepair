#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c == 0) {
    if (a == b)
      cout << 1;
    else
      cout << 0;
  } else {
    if (a == b && a != 0)
      cout << 1;
    else
      cout << 0;
  }
}
