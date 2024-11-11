#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, x, y;
  double req;
  cin >> n >> x >> y;
  req = n * y * 0.01;
  if (req != (int)req) {
    req = (int)req + 1;
  }
  if (req > x) {
    cout << req - x;
  } else {
    cout << 0;
  }
  return 0;
}
