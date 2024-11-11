#include <bits/stdc++.h>
using namespace std;
double t, i, j, bb, aa, cc;
int main() {
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> aa >> bb;
    if (aa == 0) {
      cout << 1 << endl;
      continue;
    } else if (bb == 0) {
      cout << 0.5 << endl;
      continue;
    } else if (aa / 4.0 <= bb) {
      cc = (aa * bb + aa * aa / 8.0) / (aa * bb * 2);
      printf("%.7f", cc);
      cout << endl;
      continue;
    } else {
      cc = (aa * bb + (aa - 4.0 * bb) * bb + 4.0 * bb * bb) / (2.0 * aa * bb);
      printf("%.7f", cc);
      cout << endl;
    }
  }
  return 0;
}
