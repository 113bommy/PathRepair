#include <bits/stdc++.h>
using namespace std;
int main() {
  int wh, wa, wd, mh, ma, md, ch, ca, cd;
  cin >> wh >> wa >> wd;
  cin >> mh >> ma >> md;
  cin >> ch >> ca >> cd;
  int cost = 1000000000;
  for (int da = 0; da <= 200; ++da) {
    for (int dd = 0; dd <= 200; ++dd) {
      if (wa + da - md <= 0) continue;
      int t = (mh - 1) / (wa + da - md) + 1;
      int dh = max(0, t * (ma - wd - dd) - wh + 1);
      cost = min(cost, ca * da + cd * dd + ch * dh);
    }
  }
  cout << cost << endl;
  return 0;
}
