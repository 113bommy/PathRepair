#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  long int x, y, z, w, mx;
  cin >> x >> y >> z >> w;
  mx = max(w, max(z, max(x, y)));
  if (mx == w) {
    cout << (mx - z) << "" << (mx - y) << "" << (mx - x);
  } else if (mx == z) {
    cout << (mx - w) << "" << (mx - y) << "" << (mx - x);
  } else if (mx == y) {
    cout << (mx - z) << "" << (mx - w) << "" << (mx - x);
  } else {
    cout << (mx - z) << "" << (mx - y) << "" << (mx - w);
  }
  return 0;
}
