#include <bits/stdc++.h>
using namespace std;
long long a, b, x, k;
int main() {
  cin >> k >> a >> b;
  if (b >= 0) {
    x = b / k;
    if (a > 0)
      x -= (a - 1) / k;
    else
      x -= a / k;
  } else {
    x = a / k;
    x -= (b + 1) / k;
    x *= -1;
  }
  if (a == 0 || b == 0 || (a < 0 && b > 0)) x++;
  cout << x;
  return 0;
}
