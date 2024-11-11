#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, mx;
  cin >> a >> b >> c;
  mx = max(max(a, b), c);
  if (a == mx) {
    if (a - (b + c) >= 0)
      cout << a - (b + c) + 1;
    else
      cout << 0;
  } else if (b == mx) {
    if (b - (a + c) >= 0)
      cout << b - (a + c) + 1;
    else
      cout << 0;
  } else {
    if (c - (a + b) >= 0)
      cout << c - (a + b) + 1;
    else
      cout << 0;
  }
}
