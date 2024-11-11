#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  double tmp = (n * 1.000 * y * 0.001);
  int r = ceil(tmp);
  if (r <= x) {
    cout << "0\n";
  } else {
    cout << (r - x) << endl;
  }
}
