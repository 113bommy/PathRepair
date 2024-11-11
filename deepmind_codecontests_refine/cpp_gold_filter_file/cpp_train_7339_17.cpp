#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<string> board(8);
  for (int i = 0; i < 8; i++) {
    cin >> board[i];
  }
  int mw = 8, mb = -1;
  for (int i = 0; i < 8; i++) {
    bool hasB = false, hasW = false;
    int b = -1, w = 8;
    int bmin = 8, wmax = -1;
    for (int j = 0; j < 8; j++) {
      if (board[j][i] == 'B') {
        hasB = true;
        b = max(j, b);
        bmin = min(bmin, j);
      }
      if (board[j][i] == 'W') {
        hasW = true;
        w = min(j, w);
        wmax = max(wmax, j);
      }
    }
    if (hasW && w < bmin) mw = min(mw, w);
    if (hasB && b > wmax) mb = max(mb, b);
  }
  int absw, absb;
  absw = mw - 0;
  absb = 7 - mb;
  if (absw <= absb) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
