#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, min, min1;
  cin >> n;
  int y = floor(sqrt(n));
  int z = ceil(n * 1.0 / y);
  min = 2 * (y + z);
  int y1 = ceil(sqrt(n));
  int z1 = ceil(n / y1);
  min1 = 2 * (y1 + z1);
  if (min < min1) {
    cout << min;
  } else {
    cout << min1;
  }
  return 0;
}
