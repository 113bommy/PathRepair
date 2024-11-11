#include <bits/stdc++.h>
using namespace std;
int x[1000005], y[1000005];
int main() {
  int t, n, m, cntx, cnty, mnx, mny, mxx, mxy, okx, oky;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cin >> s;
    cntx = 1;
    cnty = 1;
    mnx = 0;
    mny = 0;
    mxx = 0;
    mxy = 0;
    okx = 0;
    oky = 0;
    if (mxx - mnx + 1 == n) okx = 1;
    if (mxy - mny + 1 == m) oky = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L') {
        y[cnty] = y[cnty - 1] - 1;
        if (oky == 1 && (y[cnty] < mny || y[cnty] > mxy)) break;
        mny = min(mny, y[cnty]);
        mxy = max(mxy, y[cnty]);
        cnty++;
      } else if (s[i] == 'R') {
        y[cnty] = y[cnty - 1] + 1;
        if (oky == 1 && (y[cnty] < mny || y[cnty] > mxy)) break;
        mxy = max(mxy, y[cnty]);
        mny = min(mny, y[cnty]);
        cnty++;
      } else if (s[i] == 'U') {
        x[cntx] = x[cntx - 1] - 1;
        if (okx == 1 && (x[cntx] < mnx || x[cntx] > mxx)) break;
        mnx = min(mnx, x[cntx]);
        mxx = max(mxx, x[cntx]);
        cntx++;
      } else {
        x[cntx] = x[cntx - 1] + 1;
        if (okx == 1 && (x[cntx] < mnx || x[cntx] > mxx)) break;
        mxx = max(mxx, x[cntx]);
        mnx = min(mnx, x[cntx]);
        cntx++;
      }
      if (mxx - mnx + 1 == n) okx = 1;
      if (mxy - mny + 1 == m) oky = 1;
    }
    cout << n - mxx << " " << m - mxy << '\n';
  }
  return 0;
}
