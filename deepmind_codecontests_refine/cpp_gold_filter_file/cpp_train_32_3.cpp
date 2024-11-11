#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, u;
  cin >> n >> x >> y;
  u = n * y / 100;
  int t = (n * y) % 100;
  if (x == u && !t || x > u)
    cout << 0;
  else {
    if (t) {
      cout << u - x + 1;
    } else
      cout << u - x;
  }
  return 0;
}
