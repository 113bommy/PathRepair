#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int qu = 0; qu < int(q); qu++) {
    int n;
    cin >> n;
    int maxL = -100000, maxR = 100000, maxU = -100000, maxD = 100000;
    for (int i = 0; i < int(n); i++) {
      int currX, currY, l, u, r, d;
      cin >> currX >> currY >> l >> d >> r >> u;
      if (!l) {
        maxL = max(currX, maxL);
      }
      if (!r) {
        maxR = min(maxR, currX);
      }
      if (!u) {
        maxU = max(maxU, currY);
      }
      if (!d) {
        maxD = min(maxD, currY);
      }
    }
    if (maxL > maxR || maxD < maxU) {
      cout << "0\n";
    } else {
      cout << "1 " << maxL << " " << maxU << "\n";
    }
  }
  return 0;
}
