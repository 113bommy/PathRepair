#include <bits/stdc++.h>
using namespace std;
int main() {
  int r0, w, c, r;
  while (1) {
    cin >> r0 >> w >> c >> r;
    if (r0 + w + c + r == 0) return 0;
    if (double(r0) / w >= c) {
      cout << 0 << endl;
      continue;
    }
    cout << ceil(double(c * w - r) / r0) << endl;
  }
}
