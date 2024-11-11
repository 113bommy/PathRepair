#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int q = 1; q <= t; q++) {
    long long int aa, bb, xx, yy, nn;
    cin >> aa >> bb >> xx >> yy >> nn;
    long long int dif1 = aa - xx;
    long long int dif2 = bb - yy;
    dif1 = min(dif1, nn);
    dif2 = min(dif2, nn);
    if (aa - dif1 < bb - dif2) {
      nn -= dif1;
      aa -= dif1;
      dif2 = min(dif2, nn);
      bb -= dif2;
    } else if (aa - dif1 > bb - dif2) {
      nn -= dif2;
      bb -= dif2;
      dif1 = min(dif1, nn);
      aa -= dif1;
    } else {
      if (dif1 > dif2) {
        nn -= dif2;
        bb -= dif2;
        dif1 - min(dif1, nn);
        aa -= dif1;
      } else {
        nn -= dif1;
        aa -= dif1;
        dif2 = min(dif2, nn);
        bb -= dif2;
      }
    }
    long long int ans = aa * bb;
    cout << ans << "\n";
  }
}
