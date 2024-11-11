#include <bits/stdc++.h>
using namespace std;
int k, a, b, y;
int main() {
  cin >> k >> a >> b >> y;
  int san = 0;
  while (a > 0) {
    if (k < b + 1) {
      a -= k * y;
      b -= k - 1;
    } else {
      a -= (b + 1) * y;
      b = 0;
    }
    san++;
  }
  cout << san;
  return 0;
}
